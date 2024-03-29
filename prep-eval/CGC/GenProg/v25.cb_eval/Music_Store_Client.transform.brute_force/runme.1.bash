#!/bin/bash 
mkdir -p logs;
export ENABLE_FIXES=1
perl -pi -e'if(/blacklist-src-functions/){ undef $_; }' cfg-gp-1
for i in $(cat fn_blacklist.*.txt); do echo -ne "\n--blacklist-src-functions "$i; done  >> cfg-gp-1
perl -pi -e'if(/^\s*$/){ undef $_;};'  cfg-gp-1
/usr/bin/genprog-bl cfg-gp-1 --search brute --continue &> logs/gp.brute_force.1.log
