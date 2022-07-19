#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/FablesReport runs/FablesReport; curdir=$(pwd); pushd runs/FablesReport > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FablesReport/FablesReport.pov_1.conf -r FablesReport.pov_1  >& $curdir/logs/FablesReport/FablesReport.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FablesReport/FablesReport.pov_2.conf -r FablesReport.pov_2  >& $curdir/logs/FablesReport/FablesReport.pov_2.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FablesReport/FablesReport.pov_3.conf -r FablesReport.pov_3  >& $curdir/logs/FablesReport/FablesReport.pov_3.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FablesReport/FablesReport.pov_4.conf -r FablesReport.pov_4  >& $curdir/logs/FablesReport/FablesReport.pov_4.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FablesReport/FablesReport.pov_5.conf -r FablesReport.pov_5  >& $curdir/logs/FablesReport/FablesReport.pov_5.log
popd > /dev/null; echo "Done - FablesReport"
