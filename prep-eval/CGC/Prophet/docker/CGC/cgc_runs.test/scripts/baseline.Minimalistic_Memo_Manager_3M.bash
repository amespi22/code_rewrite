#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Minimalistic_Memo_Manager_3M runs/Minimalistic_Memo_Manager_3M; curdir=$(pwd); pushd runs/Minimalistic_Memo_Manager_3M > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Minimalistic_Memo_Manager_3M/Minimalistic_Memo_Manager_3M.pov_1.conf -r Minimalistic_Memo_Manager_3M.pov_1  >& $curdir/logs/Minimalistic_Memo_Manager_3M/Minimalistic_Memo_Manager_3M.pov_1.log
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Minimalistic_Memo_Manager_3M/Minimalistic_Memo_Manager_3M.pov_2.conf -r Minimalistic_Memo_Manager_3M.pov_2  >& $curdir/logs/Minimalistic_Memo_Manager_3M/Minimalistic_Memo_Manager_3M.pov_2.log
popd > /dev/null; echo "Done - Minimalistic_Memo_Manager_3M"
