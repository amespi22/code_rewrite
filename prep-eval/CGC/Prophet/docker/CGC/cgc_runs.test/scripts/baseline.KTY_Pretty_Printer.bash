#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/KTY_Pretty_Printer runs/KTY_Pretty_Printer; curdir=$(pwd); pushd runs/KTY_Pretty_Printer > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_1.conf -r KTY_Pretty_Printer.pov_1  >& $curdir/logs/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_2.conf -r KTY_Pretty_Printer.pov_2  >& $curdir/logs/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_2.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_3.conf -r KTY_Pretty_Printer.pov_3  >& $curdir/logs/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_3.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_4.conf -r KTY_Pretty_Printer.pov_4  >& $curdir/logs/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_4.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_5.conf -r KTY_Pretty_Printer.pov_5  >& $curdir/logs/KTY_Pretty_Printer/KTY_Pretty_Printer.pov_5.log
popd > /dev/null; echo "Done - KTY_Pretty_Printer"
