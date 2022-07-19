#!/bin/bash 
mkdir -p logs;
/usr/bin/genprog cfg-cf-gp-5 --search brute --continue &> logs/gp.brute_force.5.log
