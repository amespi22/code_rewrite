#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/simplenote runs/simplenote; curdir=$(pwd); pushd runs/simplenote > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/simplenote/simplenote.pov_2.conf -r simplenote.pov_2  >& $curdir/logs/simplenote/simplenote.pov_2.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/simplenote/simplenote.pov_2.log; fi
popd > /dev/null; echo "Done - simplenote"
