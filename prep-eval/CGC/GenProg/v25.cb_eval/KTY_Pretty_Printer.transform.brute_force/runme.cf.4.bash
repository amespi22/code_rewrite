#!/bin/bash 
mkdir -p logs;
/usr/bin/genprog cfg-cf-gp-4 --search brute --continue &> logs/gp.brute_force.4.log
