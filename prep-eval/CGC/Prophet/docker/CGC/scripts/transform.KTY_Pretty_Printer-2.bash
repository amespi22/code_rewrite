#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/KTY_Pretty_Printer runs/KTY_Pretty_Printer; curdir=$(pwd); pushd runs/KTY_Pretty_Printer > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/KTY_Pretty_Printer/transform.KTY_Pretty_Printer.pov_2.conf -r transform.KTY_Pretty_Printer.pov_2  >& $curdir/logs/KTY_Pretty_Printer/transform.KTY_Pretty_Printer.pov_2.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/KTY_Pretty_Printer/transform.KTY_Pretty_Printer.pov_2.log; fi
popd > /dev/null; echo "Done - KTY_Pretty_Printer"
