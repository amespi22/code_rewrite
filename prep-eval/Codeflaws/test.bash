#!/bin/bash

export ENABLE_FIXES=1
ARGS=( $1 )
if [[ ! -d "$1" ]] && [[ -f "$1" ]]; then 
    ARGS=$(cat $1)
fi
BASEDIR=$(pwd)
for i in ${ARGS[@]}; do
    cd $BASEDIR
    bug=$(echo $i | perl -p -e 's/-bug//g;s/-\d+$/$1.c/')
    fix=$(echo $i | perl -p -e 's/-bug//g;s/(-\d+)(-\d+)$/$2.c/')
    cb=$i
    if [[ ! -e $cb/trans-$bug ]]; then
        continue
    fi
    pushd $cb &> /dev/null
        if [[ -e orig-$bug ]]; then
            rm -f $bug
            ln -sf trans-$bug $bug
        fi
       
        make &> /dev/null
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
            echo "$i : TRANSFORM ENABLE_FIXES EXECUTABLE FAILED [${fails[@]}]"
        else
            echo "$i : TRANSFORM ENABLE_FIXES PASS [COMPILATION, TESTS]"
        fi
    popd &> /dev/null
done
