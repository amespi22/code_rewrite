#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Griswold runs/Griswold; curdir=$(pwd); pushd runs/Griswold > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Griswold/Griswold.pov_1.conf -r Griswold.pov_1  >& $curdir/logs/Griswold/Griswold.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/Griswold/Griswold.pov_1.log; fi
popd > /dev/null; echo "Done - Griswold"
