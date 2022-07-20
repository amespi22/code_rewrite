#!/usr/bin/env bash

export PREP_EVAL_DIR=$(dirname -- $(realpath -- ${BASH_SOURCE[0]}))
pushd $PREP_EVAL_DIR &> /dev/null

git clone https://github.com/pdreiter/transform-scripts.git



popd &> /dev/null
