#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/simplenote runs/simplenote; curdir=$(pwd); pushd runs/simplenote > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/simplenote/transform.simplenote.pov_1.conf -r transform.simplenote.pov_1  >& $curdir/logs/simplenote/transform.simplenote.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/simplenote/transform.simplenote.pov_1.log; fi
popd > /dev/null; echo "Done - simplenote"
