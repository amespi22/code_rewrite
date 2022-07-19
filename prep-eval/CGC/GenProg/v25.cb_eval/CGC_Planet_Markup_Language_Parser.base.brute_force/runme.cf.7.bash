#!/bin/bash 
mkdir -p logs;
/usr/bin/genprog cfg-cf-gp-7 --search brute --continue &> logs/gp.brute_force.7.log
