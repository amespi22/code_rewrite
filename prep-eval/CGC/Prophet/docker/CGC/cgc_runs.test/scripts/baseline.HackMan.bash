#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/HackMan runs/HackMan; curdir=$(pwd); pushd runs/HackMan > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/HackMan/HackMan.pov_1.conf -r HackMan.pov_1  >& $curdir/logs/HackMan/HackMan.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/HackMan/HackMan.pov_2.conf -r HackMan.pov_2  >& $curdir/logs/HackMan/HackMan.pov_2.log
popd > /dev/null; echo "Done - HackMan"
