#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/SOLFEDGE runs/SOLFEDGE; curdir=$(pwd); pushd runs/SOLFEDGE > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/SOLFEDGE/SOLFEDGE.pov_1.conf -r SOLFEDGE.pov_1  >& $curdir/logs/SOLFEDGE/SOLFEDGE.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/SOLFEDGE/SOLFEDGE.pov_2.conf -r SOLFEDGE.pov_2  >& $curdir/logs/SOLFEDGE/SOLFEDGE.pov_2.log
popd > /dev/null; echo "Done - SOLFEDGE"
