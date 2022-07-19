#!/bin/bash
id=$1
mkdir v$id.logs;
rm v$id.setup.info
(time $(for i in $(cat cb_eval.c_xlist); do ../transform-scripts/bin/setup_code_transform.bash $i v$id.cb_eval &> v$id.logs/$i.log& echo $! >> v$id.setup.info; jobs &> /dev/null; while (( $(jobs |& grep 'Running' | wc -l)>=13 )); do sleep 60; done;  done) )&> v$id.time & 
PID=$!; 
disown -h $PID; 
echo $PID >> v$id.setup.info; 
sleep 10; 
egrep -h '(CODE_EXPAN|sanity\.log|recompilation)' v$id.logs/*.log
echo "-----------------------------"
egrep -h '(CODE_EXPAN|sanity\.log|recompilation)' v$id.logs/*.log | egrep -v "PASS"
