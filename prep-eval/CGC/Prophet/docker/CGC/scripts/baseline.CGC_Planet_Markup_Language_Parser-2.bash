#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/CGC_Planet_Markup_Language_Parser runs/CGC_Planet_Markup_Language_Parser; curdir=$(pwd); pushd runs/CGC_Planet_Markup_Language_Parser > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_2.conf -r CGC_Planet_Markup_Language_Parser.pov_2  >& $curdir/logs/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_2.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/CGC_Planet_Markup_Language_Parser/CGC_Planet_Markup_Language_Parser.pov_2.log; fi
popd > /dev/null; echo "Done - CGC_Planet_Markup_Language_Parser"
