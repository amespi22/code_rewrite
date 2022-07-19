#!/bin/bash 
mkdir -p logs;
/usr/bin/genprog cfg-cf-gp-2 --search brute --continue &> logs/gp.brute_force.2.log
