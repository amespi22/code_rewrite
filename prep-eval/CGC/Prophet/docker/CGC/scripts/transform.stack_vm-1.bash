#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/stack_vm runs/stack_vm; curdir=$(pwd); pushd runs/stack_vm > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/stack_vm/transform.stack_vm.pov_1.conf -r transform.stack_vm.pov_1  >& $curdir/logs/stack_vm/transform.stack_vm.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/stack_vm/transform.stack_vm.pov_1.log; fi
popd > /dev/null; echo "Done - stack_vm"
