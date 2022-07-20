#!/bin/bash

BUG_LIST=$CODEFLAWS_BASE/bug-list

if [[ -z $1 ]]; then 
    OVERWRITE_JSON=0
else
    OVERWRITE_JSON=1
fi
BASEDIR=$(pwd)
for i in $(cat $BUG_LIST ); do
    cd $BASEDIR
    if [[ ! -d $i ]]; then
        echo "directory '$i' does not exist"
        break 1;
    fi
    bug=$(echo $i | perl -p -e 's/-bug//g;s/-\d+$/$1.c/')
    fix=$(echo $i | perl -p -e 's/-bug//g;s/(-\d+)(-\d+)$/$2.c/')
    #echo -e "\nProcessing $i - [bug : $bug] ; [fix : $fix]"
    cb=$i
    exe=$(echo $bug | sed 's/\.c//')
    dir=json_input/$cb
    mkdir -p $dir
    rdir=$(realpath -- $dir)
    jdir=$(dirname -- $rdir)
    
    if (( $OVERWRITE_JSON==1 )); then 
        pushd $cb &> /dev/null
            if [[ ! -f "orig-$bug" ]]; then
                cp $bug orig-$bug 
            fi
            rm -f $bug
            ln -sf orig-$bug $bug
           
            ( make; echo $?) &> make.log
            if [[ ! -e $exe ]]; then
                echo "$i : BASELINE COMPILATION FAILED"
                popd &> /dev/null
                continue
            fi
            $(make |& egrep -w 'gcc' | egrep '\-c' | sed 's/gcc/gcc -H/') &> $rdir/make.log
            $(make |& egrep -w 'gcc' | egrep -w '\-s' | sed 's/ \-s / /') &> /dev/null
            cat json_input/make.log |& egrep -w '(^\.|\-H)' | \
               perl -p -e'if(/.*\-c\s+(.*\.c)/){ s/.*\-c\s+(.*\.c).*/$1:/; } elsif(!/^\.+ /){ undef $_; }; ' > $rdir/make.deps
            $CODEFLAWS_BASE/../transform-scripts/bin/depend.py --dependency-file $rdir/make.deps  > $rdir/cb.deps.json
            nm -C $exe | egrep -w '[tTuUwW]' | \
                awk '{print $NF}' | sort -u | sed 's/@.*//' | sort -u | \
                perl -p -e's/^/"/;s/$/",/;chomp($_);' \
                   > $rdir/cb.symbols
            egrep '# *define' orig-$bug | \
                perl -pe 'if(/#\s*define\s+([^(\s]+)\s*(\(.+)/){print("\"$1\",");}; undef $_;' \
                   > $rdir/cb.macro_fns
            (cat $rdir/cb.symbols $rdir/cb.macro_fns | perl -pe 's/\r?\n//' | \
               perl -p -e's/,$//'; ) > $rdir/cb.disable_eval 
            (echo -e "\"disable_eval\":\n["; \
                cat $rdir/cb.disable_eval; \
                echo "],"; ) \
                   > $rdir/cb.disable_eval.json
            ( echo -e "\"macros\": ["; egrep '# *define' orig-$bug | \
                perl -pe 'if(/#\s*define\s+([^(\s]+)\s+([^\/]+)/){$n=$1;$v=$2; $v=~s/"/\\"/g;$v=~s/[\r\n]//g;$_="{\"name\":\"$n\",\"value\":\"$v\"},";} else{ undef $_;}' | \
                sed 's/,$//'; echo -e "\n]\n" ) > $rdir/cb.macros.json
            (echo "{";cat $rdir/cb.deps.json;echo ","; \
               cat $rdir/cb.disable_eval.json;\
               cat $rdir/cb.macros.json; echo -e "\n}") > $rdir/cb.json
            ln -sf $rdir/cb.json $jdir/$cb.json
        popd &> /dev/null
    fi
    mkdir -p xform/$cb
    cp $cb/orig-$bug xform/$cb/$bug
    $CODE_EXPAND_PATH/code_expand.py -n xform/$cb/$bug -f xform/$cb/t-$bug -p $jdir/$cb.json &> xform/$cb/xform.log 
    cp xform/$cb/xform.log $cb/
    [[ -e debug.log ]] && mv debug.log $cb/debug.log 
    if [[ ! -e xform/$cb/t-$bug ]]; then
        echo "$i : TRANSFORMATION FAILED"
        continue 
    fi
    cp xform/$cb/t-$bug $cb/trans-$bug
    ln -sf trans-$bug $cb/$bug

    pushd $cb &> /dev/null
        make &> make.trans.log
        res=$?
        if (( $res!=0 )); then
            echo "$i : TRANSFORM COMPILATION FAILED"
            popd &> /dev/null
            continue 
        fi
        run_fail=0
        fails=()
        for t in $(cat ./test-genprog.sh  | perl -p -e'if (/^([np]\d+)\)/){ print ("$1\n"); } undef $_;'); do
            ENABLE_FIXES=1 timeout --preserve-status -k 60 60 ./test-genprog.sh $t &> /dev/null
            res=$?
            is_neg=$(echo $t | egrep -c '^n')
            if (( $is_neg==1 )); then
                if (( $res==0 )); then (( run_fail+=1 )); fails+=( $t ); fi
            else
                if (( $res!=0 )); then (( run_fail+=1 )); fails+=( $t ); fi
            fi
        done
        if (( $run_fail>0 )); then
            echo "$i : TRANSFORMED EXECUTABLE FAILED [${fails[@]}] (ENABLE_FIXES=1)"
        else
            echo "$i : TRANSFORMATIONS PASS [TRANSFORMS, COMPILATION, TESTS] (ENABLE_FIXES=1)"
        fi
    popd &> /dev/null
done

echo "Done."
