#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Palindrome runs/Palindrome; curdir=$(pwd); pushd runs/Palindrome > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Palindrome/transform.Palindrome.pov_1.conf -r transform.Palindrome.pov_1  >& $curdir/logs/Palindrome/transform.Palindrome.pov_1.log
popd > /dev/null; echo "Done - Palindrome"
