#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Diary_Parser runs/Diary_Parser; curdir=$(pwd); pushd runs/Diary_Parser > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Diary_Parser/transform.Diary_Parser.pov_1.conf -r transform.Diary_Parser.pov_1  >& $curdir/logs/Diary_Parser/transform.Diary_Parser.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/Diary_Parser/transform.Diary_Parser.pov_1.log; fi
popd > /dev/null; echo "Done - Diary_Parser"
