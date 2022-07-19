#!/bin/bash 

cb=$1
export CB=$cb
RUN_DIR=$2

SCRIPT_DIR=$(dirname -- $(realpath $0))
poll_base_dir=$(realpath -- ../polls/$cb)
test_base_dir=$(realpath -- ../cgc_test/$cb)
CGC_CB_DIR=$(realpath -- ../cgc_cb_dir)

TRANSFORM_SRC=$SCRIPT_DIR/trans.src

if [[ -z $CGC_CB_DIR ]] || [[ ! -d $TRANSFORM_SRC/$CB ]] ; then 
	[[ -z $CGC_CB_DIR ]] && echo "ERROR: CGC CB Environment not set up!";
	[[ ! -d $TRANSFORM_SRC/$CB ]] && echo "ERROR: CGC CB $CB has not been transformed!";
	echo "Cannot continue."
	exit -1
fi;
if [[ -z $RUN_DIR ]]; then RUN_DIR=$SCRIPT_DIR; fi
BASH_SCRIPT=$(realpath -- $RUN_DIR)/run-scripts/$CB.bash
mkdir -p $(dirname -- $BASH_SCRIPT)

oracle_dir=$(realpath -- $SCRIPT_DIR/cgc_oracles/$cb)
local_oracle_dir="cgc_oracles/$cb"
num_tests=$(ls $oracle_dir/ | grep seed | wc -l)
num_neg_tests=$(ls $oracle_dir/ | grep 'seed\.n' | wc -l)
if [[ $num_neg_tests -eq 0 ]]; then 
    echo "ERROR: No negative tests available for '$CB'!  Cannot continue."
    exit -1
fi
    
ID=0
WORKDIR=$PWD
mkdir -p $RUN_DIR/polls $RUN_DIR/cgc_test/$cb
cp -r $poll_base_dir $RUN_DIR/polls/
cp -r $test_base_dir/test.sh $RUN_DIR/cgc_test/$cb/
mkdir -p $RUN_DIR/cgc_oracles
cp -r $oracle_dir $RUN_DIR/cgc_oracles/$cb
perl -pi -e's/(#!\/bin\/bash)/$1\nSCRIPT_DIR=\$(dirname -- \$(realpath -- \$0))/' $RUN_DIR/cgc_oracles/$cb/oracle
perl -pi -e's#/mnt/Data/APR_eval/cgc_oracles/'$cb'#\$SCRIPT_DIR#g' $RUN_DIR/cgc_oracles/$cb/oracle
for CFG in "base" "trans"; do 
    (( ID+=1 ))
    CB_RUN_DIR=$RUN_DIR/cgc_runs-$CFG/$cb
    (( start_pos=$num_neg_tests+1 ))
    
    if [[ ! -d $CB_RUN_DIR ]]; then
    	mkdir -p $CB_RUN_DIR
    	cd $CB_RUN_DIR
    	cp $SCRIPT_DIR/templates/Makefile ./
    	cp -r $SCRIPT_DIR/templates/source/include ./
    	#cp -r $SCRIPT_DIR/transform.src/$CB $dir/
        if (( $ID==1 )); then 
    	    cp -r $CGC_CB_DIR/challenges/$cb ./
        else
    	    cp -r $TRANSFORM_SRC/$cb ./
        fi
    	cp $SCRIPT_DIR/templates/CMakeLists.txt ./
    else
    	echo "$CB_RUN_DIR already set up [neg : $num_neg_tests] [$start_pos,$num_tests]"
    fi;
    cd $WORKDIR
done

echo    '#!/bin/bash' > $BASH_SCRIPT
echo -e '\nSCRIPT_DIR=$(dirname -- $(realpath -- $0))' >> $BASH_SCRIPT
echo -e 'BASE_DIR=$(dirname -- $SCRIPT_DIR)' >> $BASH_SCRIPT
echo -e 'CB='"$cb" >> $BASH_SCRIPT
echo -e 'ORACLE_DIR=$BASE_DIR/'"$local_oracle_dir" >> $BASH_SCRIPT
echo -e 'BASELINE_DIR=$BASE_DIR/cgc_runs-base/'"$cb" >> $BASH_SCRIPT
echo -e 'TRANSFORM_DIR=$BASE_DIR/cgc_runs-trans/'"$cb\n\n" >> $BASH_SCRIPT
dir=$RUN_DIR/cgc_runs-base/$cb

flist=""
for f in $(ls $dir/$cb/src/*.c); do
   file=$(echo $f | sed "s#^$dir/##")
   flist+=" $file"
done
localize_cnt=$(ls $dir/$cb/src/*.c | wc -l)
tlist=$(seq $start_pos $num_tests)
driver="\$ORACLE_DIR/oracle"
build_cmd="CB=$CB make all"

for n in $(seq 1 $num_neg_tests); do 
        f1x_cmd="f1x -o patch_n$n --files $flist --driver $driver --tests $n $tlist --test-timeout 5000 --verbose --build \"$build_cmd\" |& tee f1x.\$CB.$n.log"
        echo -e 'cd $BASELINE_DIR\nmkdir -p patch_n'$n'\n'$f1x_cmd >> $BASH_SCRIPT
        echo -e 'cd $TRANSFORM_DIR\nmkdir -p patch_n'$n'\n'$f1x_cmd >> $BASH_SCRIPT
done

chmod +x $BASH_SCRIPT
echo "Done - $cb"
