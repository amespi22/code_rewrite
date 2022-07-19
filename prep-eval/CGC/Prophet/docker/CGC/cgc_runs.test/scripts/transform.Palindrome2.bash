#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Palindrome2 runs/Palindrome2; curdir=$(pwd); pushd runs/Palindrome2 > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Palindrome2/transform.Palindrome2.pov_1.conf -r transform.Palindrome2.pov_1  >& $curdir/logs/Palindrome2/transform.Palindrome2.pov_1.log
popd > /dev/null; echo "Done - Palindrome2"
