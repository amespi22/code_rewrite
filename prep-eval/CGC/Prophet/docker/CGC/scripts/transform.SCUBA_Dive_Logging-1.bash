#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/SCUBA_Dive_Logging runs/SCUBA_Dive_Logging; curdir=$(pwd); pushd runs/SCUBA_Dive_Logging > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/SCUBA_Dive_Logging/transform.SCUBA_Dive_Logging.pov_1.conf -r transform.SCUBA_Dive_Logging.pov_1  >& $curdir/logs/SCUBA_Dive_Logging/transform.SCUBA_Dive_Logging.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/SCUBA_Dive_Logging/transform.SCUBA_Dive_Logging.pov_1.log; fi
popd > /dev/null; echo "Done - SCUBA_Dive_Logging"
