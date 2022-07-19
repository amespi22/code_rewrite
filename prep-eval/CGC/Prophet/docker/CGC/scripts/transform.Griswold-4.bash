#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Griswold runs/Griswold; curdir=$(pwd); pushd runs/Griswold > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Griswold/transform.Griswold.pov_4.conf -r transform.Griswold.pov_4  >& $curdir/logs/Griswold/transform.Griswold.pov_4.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/Griswold/transform.Griswold.pov_4.log; fi
popd > /dev/null; echo "Done - Griswold"
