#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/FISHYXML runs/FISHYXML; curdir=$(pwd); pushd runs/FISHYXML > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FISHYXML/transform.FISHYXML.pov_1.conf -r transform.FISHYXML.pov_1  >& $curdir/logs/FISHYXML/transform.FISHYXML.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FISHYXML/transform.FISHYXML.pov_2.conf -r transform.FISHYXML.pov_2  >& $curdir/logs/FISHYXML/transform.FISHYXML.pov_2.log
popd > /dev/null; echo "Done - FISHYXML"
