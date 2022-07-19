#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/On_Sale runs/On_Sale; curdir=$(pwd); pushd runs/On_Sale > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/On_Sale/transform.On_Sale.pov_1.conf -r transform.On_Sale.pov_1  >& $curdir/logs/On_Sale/transform.On_Sale.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/On_Sale/transform.On_Sale.pov_2.conf -r transform.On_Sale.pov_2  >& $curdir/logs/On_Sale/transform.On_Sale.pov_2.log
popd > /dev/null; echo "Done - On_Sale"
