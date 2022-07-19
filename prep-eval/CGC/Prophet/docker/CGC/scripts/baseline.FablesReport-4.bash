#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/FablesReport runs/FablesReport; curdir=$(pwd); pushd runs/FablesReport > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FablesReport/FablesReport.pov_4.conf -r FablesReport.pov_4  >& $curdir/logs/FablesReport/FablesReport.pov_4.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/FablesReport/FablesReport.pov_4.log; fi
popd > /dev/null; echo "Done - FablesReport"
