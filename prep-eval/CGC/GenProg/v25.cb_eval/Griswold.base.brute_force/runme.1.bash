#!/bin/bash 
mkdir -p logs;
/usr/bin/genprog cfg-gp-1 --search brute --continue &> logs/gp.brute_force.1.log
