#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/QuadtreeConways runs/QuadtreeConways; curdir=$(pwd); pushd runs/QuadtreeConways > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/QuadtreeConways/QuadtreeConways.pov_1.conf -r QuadtreeConways.pov_1  >& $curdir/logs/QuadtreeConways/QuadtreeConways.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/QuadtreeConways/QuadtreeConways.pov_1.log; fi
popd > /dev/null; echo "Done - QuadtreeConways"
