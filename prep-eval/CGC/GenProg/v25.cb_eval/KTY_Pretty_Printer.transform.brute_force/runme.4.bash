#!/bin/bash 
mkdir -p logs;
export ENABLE_FIXES=1
perl -pi -e'if(/blacklist-src-functions/){ undef $_; }' cfg-gp-4
for i in $(cat fn_blacklist.*.txt); do echo -ne "\n--blacklist-src-functions "$i; done  >> cfg-gp-4
perl -pi -e'if(/^\s*$/){ undef $_;};'  cfg-gp-4
/usr/bin/genprog-bl cfg-gp-4 --search brute --continue &> logs/gp.brute_force.4.log
