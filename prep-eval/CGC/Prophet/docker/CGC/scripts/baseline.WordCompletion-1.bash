#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/WordCompletion runs/WordCompletion; curdir=$(pwd); pushd runs/WordCompletion > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/WordCompletion/WordCompletion.pov_1.conf -r WordCompletion.pov_1  >& $curdir/logs/WordCompletion/WordCompletion.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/WordCompletion/WordCompletion.pov_1.log; fi
popd > /dev/null; echo "Done - WordCompletion"
