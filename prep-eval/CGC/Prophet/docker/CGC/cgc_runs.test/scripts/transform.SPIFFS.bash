#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/SPIFFS runs/SPIFFS; curdir=$(pwd); pushd runs/SPIFFS > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/SPIFFS/transform.SPIFFS.pov_1.conf -r transform.SPIFFS.pov_1  >& $curdir/logs/SPIFFS/transform.SPIFFS.pov_1.log
popd > /dev/null; echo "Done - SPIFFS"
