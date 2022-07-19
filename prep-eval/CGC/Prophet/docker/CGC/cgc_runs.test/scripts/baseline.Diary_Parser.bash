#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Diary_Parser runs/Diary_Parser; curdir=$(pwd); pushd runs/Diary_Parser > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Diary_Parser/Diary_Parser.pov_1.conf -r Diary_Parser.pov_1  >& $curdir/logs/Diary_Parser/Diary_Parser.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Diary_Parser/Diary_Parser.pov_2.conf -r Diary_Parser.pov_2  >& $curdir/logs/Diary_Parser/Diary_Parser.pov_2.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Diary_Parser/Diary_Parser.pov_3.conf -r Diary_Parser.pov_3  >& $curdir/logs/Diary_Parser/Diary_Parser.pov_3.log
popd > /dev/null; echo "Done - Diary_Parser"
