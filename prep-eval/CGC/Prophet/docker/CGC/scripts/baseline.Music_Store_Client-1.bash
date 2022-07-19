#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Music_Store_Client runs/Music_Store_Client; curdir=$(pwd); pushd runs/Music_Store_Client > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Music_Store_Client/Music_Store_Client.pov_1.conf -r Music_Store_Client.pov_1  >& $curdir/logs/Music_Store_Client/Music_Store_Client.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/Music_Store_Client/Music_Store_Client.pov_1.log; fi
popd > /dev/null; echo "Done - Music_Store_Client"
