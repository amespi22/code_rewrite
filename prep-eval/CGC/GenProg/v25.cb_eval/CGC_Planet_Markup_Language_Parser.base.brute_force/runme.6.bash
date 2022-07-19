#!/bin/bash 
mkdir -p logs;
/usr/bin/genprog cfg-gp-6 --search brute --continue &> logs/gp.brute_force.6.log
