#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/FISHYXML runs/FISHYXML; curdir=$(pwd); pushd runs/FISHYXML > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FISHYXML/FISHYXML.pov_1.conf -r FISHYXML.pov_1  >& $curdir/logs/FISHYXML/FISHYXML.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/FISHYXML/FISHYXML.pov_1.log; fi
popd > /dev/null; echo "Done - FISHYXML"
