#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/WordCompletion runs/WordCompletion; curdir=$(pwd); pushd runs/WordCompletion > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/WordCompletion/transform.WordCompletion.pov_1.conf -r transform.WordCompletion.pov_1  >& $curdir/logs/WordCompletion/transform.WordCompletion.pov_1.log
popd > /dev/null; echo "Done - WordCompletion"
