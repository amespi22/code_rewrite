#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/cotton_swab_arithmetic runs/cotton_swab_arithmetic; curdir=$(pwd); pushd runs/cotton_swab_arithmetic > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/cotton_swab_arithmetic/transform.cotton_swab_arithmetic.pov_1.conf -r transform.cotton_swab_arithmetic.pov_1  >& $curdir/logs/cotton_swab_arithmetic/transform.cotton_swab_arithmetic.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/cotton_swab_arithmetic/transform.cotton_swab_arithmetic.pov_1.log; fi
popd > /dev/null; echo "Done - cotton_swab_arithmetic"
