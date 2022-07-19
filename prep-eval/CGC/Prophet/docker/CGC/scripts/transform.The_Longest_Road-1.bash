#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/The_Longest_Road runs/The_Longest_Road; curdir=$(pwd); pushd runs/The_Longest_Road > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/The_Longest_Road/transform.The_Longest_Road.pov_1.conf -r transform.The_Longest_Road.pov_1  >& $curdir/logs/The_Longest_Road/transform.The_Longest_Road.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/The_Longest_Road/transform.The_Longest_Road.pov_1.log; fi
popd > /dev/null; echo "Done - The_Longest_Road"
