#!/bin/bash 
ID=0;

# NOTE - Make sure that the docker images have been built using the Makefile
DOCKER_IMAGE="cgc-pr-tr:latest"

RESULTS_DIR=$(dirname -- $(realpath -- ${BASH_SOURCE[0]}))"/prophet_results"
mkdir -p $RESULTS_DIR

for F in $(cat ../cb_eval.c_xlist); do 
    (( ID+=1 )); 
    mkdir -p docker-runs-$ID/logs docker-runs-$ID/runs; 
    docker run --rm --name cgc-prophet-rerun-$ID -v $RESULTS_DIR/docker-runs-$ID/logs:/CGC/cgc_runs.test/logs -v  $RESULTS_DIR/docker-runs-$ID/runs:/CGC/cgc_runs.test/runs $DOCKER_IMAGE /CGC/scripts/$F.bash &
    PID=$!; disown -h $PID
    echo $F >> launched-list
    x=$(ps -a -u $(whoami) -f | egrep -w $(whoami) | egrep -c '/CGC/scripts/' )
    while (( $x>8 )); do
        sleep 3600;
        x=$(ps -a -u $(whoami) -f | egrep -w $(whoami) | egrep -c '/CGC/scripts/' )
    done
    
done
