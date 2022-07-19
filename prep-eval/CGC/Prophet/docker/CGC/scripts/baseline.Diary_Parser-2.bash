#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Diary_Parser runs/Diary_Parser; curdir=$(pwd); pushd runs/Diary_Parser > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Diary_Parser/Diary_Parser.pov_2.conf -r Diary_Parser.pov_2  >& $curdir/logs/Diary_Parser/Diary_Parser.pov_2.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/Diary_Parser/Diary_Parser.pov_2.log; fi
popd > /dev/null; echo "Done - Diary_Parser"
