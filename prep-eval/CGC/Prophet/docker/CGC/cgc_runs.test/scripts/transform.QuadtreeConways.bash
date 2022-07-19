#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/QuadtreeConways runs/QuadtreeConways; curdir=$(pwd); pushd runs/QuadtreeConways > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/QuadtreeConways/transform.QuadtreeConways.pov_1.conf -r transform.QuadtreeConways.pov_1  >& $curdir/logs/QuadtreeConways/transform.QuadtreeConways.pov_1.log
popd > /dev/null; echo "Done - QuadtreeConways"
