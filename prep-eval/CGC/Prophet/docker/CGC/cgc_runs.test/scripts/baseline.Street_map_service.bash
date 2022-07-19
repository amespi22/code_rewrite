#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Street_map_service runs/Street_map_service; curdir=$(pwd); pushd runs/Street_map_service > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Street_map_service/Street_map_service.pov_1.conf -r Street_map_service.pov_1  >& $curdir/logs/Street_map_service/Street_map_service.pov_1.log
popd > /dev/null; echo "Done - Street_map_service"
