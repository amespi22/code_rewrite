#!/bin/bash 
mkdir -p logs;
/usr/bin/genprog cfg-gp-3 --search brute --continue &> logs/gp.brute_force.3.log
