#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/CGC_Planet_Markup_Language_Parser runs/CGC_Planet_Markup_Language_Parser; curdir=$(pwd); pushd runs/CGC_Planet_Markup_Language_Parser > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_1.conf -r CGC_Planet_Markup_Language_Parser.pov_1  >& $curdir/logs/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_2.conf -r CGC_Planet_Markup_Language_Parser.pov_2  >& $curdir/logs/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_2.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_3.conf -r CGC_Planet_Markup_Language_Parser.pov_3  >& $curdir/logs/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_3.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_4.conf -r CGC_Planet_Markup_Language_Parser.pov_4  >& $curdir/logs/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_4.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_5.conf -r CGC_Planet_Markup_Language_Parser.pov_5  >& $curdir/logs/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_5.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_6.conf -r CGC_Planet_Markup_Language_Parser.pov_6  >& $curdir/logs/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_6.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_7.conf -r CGC_Planet_Markup_Language_Parser.pov_7  >& $curdir/logs/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_7.log
popd > /dev/null; echo "Done - CGC_Planet_Markup_Language_Parser"
