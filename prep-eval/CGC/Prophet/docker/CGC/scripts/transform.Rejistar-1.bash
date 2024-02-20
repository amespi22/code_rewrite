#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Rejistar runs/Rejistar; curdir=$(pwd); pushd runs/Rejistar > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Rejistar/transform.Rejistar.pov_1.conf -r transform.Rejistar.pov_1  >& $curdir/logs/Rejistar/transform.Rejistar.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/Rejistar/transform.Rejistar.pov_1.log; fi
popd > /dev/null; echo "Done - Rejistar"