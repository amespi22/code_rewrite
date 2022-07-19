#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/FSK_BBS runs/FSK_BBS; curdir=$(pwd); pushd runs/FSK_BBS > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/FSK_BBS/FSK_BBS.pov_1.conf -r FSK_BBS.pov_1  >& $curdir/logs/FSK_BBS/FSK_BBS.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/FSK_BBS/FSK_BBS.pov_1.log; fi
popd > /dev/null; echo "Done - FSK_BBS"
