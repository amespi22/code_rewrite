#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/online_job_application2 runs/online_job_application2; curdir=$(pwd); pushd runs/online_job_application2 > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/online_job_application2/transform.online_job_application2.pov_1.conf -r transform.online_job_application2.pov_1  >& $curdir/logs/online_job_application2/transform.online_job_application2.pov_1.log
res=$?;
if (( $res==124 )); then echo " PROPHET TIMEOUT " >> $curdir/logs/online_job_application2/transform.online_job_application2.pov_1.log; fi
popd > /dev/null; echo "Done - online_job_application2"
