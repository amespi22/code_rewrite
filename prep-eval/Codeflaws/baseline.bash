#!/bin/bash

BUG_LIST=$CODEFLAWS_BASE/bug-list
for i in $(cat $BUG_LIST ); do
    bug=$(echo $i | perl -p -e 's/-bug//g;s/-\d+$/$1.c/')
    fix=$(echo $i | perl -p -e 's/-bug//g;s/(-\d+)(-\d+)$/$2.c/')
    cb=$i
    pushd $cb &> /dev/null
        if [[ -e orig-$bug ]]; then
            rm -f $bug
            ln -sf orig-$bug $bug
        fi
       
        make &> /dev/null
        res=$?
        if (( $res!=0 )); then
            echo "$i : BASELINE COMPILATION FAILED"
            continue
        fi
        run_fail=0
        fails=()
        for t in $(cat ./test-genprog.sh  | perl -p -e'if (/^([np]\d+)\)/){ print ("$1\n"); } undef $_;'); do
            timeout --preserve-status -k 60 60 ./test-genprog.sh $t &> /dev/null
            res=$?
            is_neg=$(echo $t | egrep -c '^n')
            if (( $is_neg==1 )); then
                if (( $res==0 )); then (( run_fail+=1 )); fails+=( $t ); fi
            else
                if (( $res!=0 )); then (( run_fail+=1 )); fails+=( $t ); fi
            fi
        done
        if (( $run_fail>0 )); then
            echo "$i : BASELINE EXECUTABLE FAILED [${fails[@]}]"
        else
            echo "$i : BASELINE PASS [COMPILATION, TESTS]"
        fi
    popd &> /dev/null
done
