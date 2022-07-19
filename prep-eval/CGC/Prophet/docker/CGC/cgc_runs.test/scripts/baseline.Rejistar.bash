#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Rejistar runs/Rejistar; curdir=$(pwd); pushd runs/Rejistar > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Rejistar/Rejistar.pov_1.conf -r Rejistar.pov_1  >& $curdir/logs/Rejistar/Rejistar.pov_1.log
popd > /dev/null; echo "Done - Rejistar"
