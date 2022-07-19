#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/HIGHCOO runs/HIGHCOO; curdir=$(pwd); pushd runs/HIGHCOO > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/HIGHCOO/transform.HIGHCOO.pov_1.conf -r transform.HIGHCOO.pov_1  >& $curdir/logs/HIGHCOO/transform.HIGHCOO.pov_1.log
popd > /dev/null; echo "Done - HIGHCOO"
