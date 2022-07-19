#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Griswold runs/Griswold; curdir=$(pwd); pushd runs/Griswold > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Griswold/transform.Griswold.pov_1.conf -r transform.Griswold.pov_1  >& $curdir/logs/Griswold/transform.Griswold.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Griswold/transform.Griswold.pov_2.conf -r transform.Griswold.pov_2  >& $curdir/logs/Griswold/transform.Griswold.pov_2.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Griswold/transform.Griswold.pov_3.conf -r transform.Griswold.pov_3  >& $curdir/logs/Griswold/transform.Griswold.pov_3.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Griswold/transform.Griswold.pov_4.conf -r transform.Griswold.pov_4  >& $curdir/logs/Griswold/transform.Griswold.pov_4.log
popd > /dev/null; echo "Done - Griswold"
