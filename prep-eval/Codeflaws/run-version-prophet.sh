#!/bin/bash
# Script to run prophet on subjects in codeflaws directory
#The following variables needs to be changed:
#rootdir="/home/ubuntu/codeforces-crawler/CodeforcesSpider" #directory of this script
rootdir=$(dirname -- ${BASH_SOURCE[0]}) #directory of this script
currentTime=$(date +"%Y-%m-%d-%H-%M-%S")
RUN_VERSION="base"
rundir="$rootdir/prophet-run-$RUN_VERSION" # directory in which prophet is called from, a temporary output directory where everything will be copied to during the repair
LOGFILE="$rootdir/prophet-summary-$RUN_VERSION.log"
mkdir -p $rundir
#versiondir="$rootdir/codeflaws" #root directory for the codeflaws versions
versiondir="$CODEFLAWS_BASE/codeflaws" #directory where the codeflaws.tar.gz is extracted
filename="$rootdir/run1" #should be a copy of the codeflaws-defect-detail-info.txt, or select several defects from codeflaws-defect-detail-info.txt

# MAKE SURE YOU UPDATE THIS
prophet="/home/ubuntu/spr/src/prophet" # location of the installed prophet executable

# Read arguments
if [ $# -lt 1 ]; then
  echo -e "Usage: $0 <filename> [--use-nsynth]\n"
  echo "<filename>       Input file contains subjects/versions"
  exit 1
else
  # Get the filename
  filename="$1"
  echo -e "File: $1"
  # Check if filename is existent
  if ! [ -e $filename ]; then
    echo -e "Error: $filename - no such file!"
    exit 1
  fi
fi

list=$(cut -d$'\t' -f1 $filename)
parafile="$rootdir/para-rext-all.out" 

printf "%s\t%s\t%s\n" "PROGRAM-BUG" "STATUS|REPAIRED?" "TIME" > "$LOGFILE"
printf "%s\t%s\t%s\n" "-----------" "------------------" "---------------" \
  >> "$LOGFILE"
while read -r line; do
if [[ "$line" == *"-bug-"* ]]; then 
  version=$line
  if ! grep -q "$version" $rootdir/versions-ignored-all.txt; then
     #get buggy filename from directory name:
     contestnum=$(echo $version | cut -d$'-' -f1) 
     probnum=$(echo $version | cut -d$'-' -f2)
     buggyfile=$(echo $version | cut -d$'-' -f4)
     cfile=$(echo "$contestnum-$probnum-$buggyfile".c)
     cfixfile=$(echo "$contestnum-$probnum-$buggyfile"-fix.c)
     DIRECTORY="$versiondir/$version"
     if [ ! -d "$DIRECTORY" ]; then
        echo "FOLDER DOESNT EXIST: $version"
     fi
    
     echo "Running on version:$version"; 
     cd $rundir 
    
     # create configuration file
     rm -f repair-$version.conf 
     echo "revision_file=$versiondir/$version/$cfile".revlog>>repair-$version.conf 
     echo "src_dir=$versiondir/$version/">>repair-$version.conf 
     echo "test_dir=$versiondir/$version/">>repair-$version.conf 
     echo "dep_dir=">>repair-$version.conf
     echo "build_cmd=$rootdir/code-build.py">>repair-$version.conf  
     echo "test_cmd=$rootdir/run-test-enable-fixes.py">>repair-$version.conf
     echo "localizer=profile">>repair-$version.conf
     echo "bugged_file=$cfile">>repair-$version.conf
     echo "fixed_out_file=$cfixfile">>repair-$version.conf
     echo "single_case_timeout=50">>repair-$version.conf
     rm -rf tempworkdir-$version 

     echo "RUNNING CMD:$prophet -r tempworkdir-$version/ -timeout 1"
     `which time` -o time-$version.out -f "%es" timeout -k 3600s 3600s "$prophet" -r tempworkdir-$version/ -feature-para "$parafile" -skip-verify -cond-ext -replace-ext -timeout 1 repair-$version.conf &> temp-$version.out
     timespent=$(cat "$rundir/time-$version.out" | tail -1 | tr -d '\n' | awk '{print $NF}')
     if [ -z "${timespent}" ]; then
         printf "%s\t%s\t%s\n" "$version" "TIMEOUT" "3600s" >> "$LOGFILE"
     elif grep "Command exited with non-zero status 124" "$rundir/time-$version.out"; then
         printf "%s\t%s\t%s\n" "$version" "TIMEOUT" "3600s" >> "$LOGFILE"
     fi 
     if grep -q "Failed to make" tempworkdir-$version/build.log; then
        echo "BUILD FAILED"
        printf "%s\t%s\t%s\n" "$version" "BUILDFAILED!" "$timespent" >> "$LOGFILE"
     elif  grep -q "Verification failed!" temp-$version.out; then
        printf "%s\t%s\n" "$version" "FAILVERIFY">>$rootdir/rerun.log
        if  grep -q "Unexpected pass" temp-$version.out; then
            echo "Unexpected pass"
            printf "%s\t%s\t%s\n" "$version" "Unexpected Pass" "$timespent" >> "$LOGFILE"
            printf "%s #Unexpected pass\n" "$version" >> $rootdir/ignore-list 
        elif grep -q "Unexpected fail" temp-$version.out; then
            echo "Unexpected fail"
            if tail -n 1 tempworkdir-$version/src/input-pos* | grep -E "\.\.\.$"; then
               printf "%s\t%s\t%s\n" "$version" "DOTDOTFILE" "$timespent" >> "$LOGFILE"
            fi
        fi
     elif grep -q "Timeout" time-$version.out; then
          printf "%s\t%s\t%s\n" "$version" "TIMEOUT" "$timespent" >> "$LOGFILE"
     elif grep -q "Found a fix!" temp-$version.out; then
          $rootdir/validate-fix-prophet.sh "$version" "temp-$version.out" "$timespent" "$RUN_VERSION"
          echo "PASS:$passt" 
     elif grep -q "without working fix" temp-$version.out; then
          printf "%s\t%s\t%s\n" "$version" "NO" "$timespent" >> "$LOGFILE"
     fi

  else
    echo "IGNORING:$version"  
  fi 
fi
done <<< "$list"
