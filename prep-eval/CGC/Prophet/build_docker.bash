#!/usr/bin/env bash

cd docker/patches; 
if [[ ! -e llvm.patch ]] ; then  gunzip llvm.patch.gz; fi
cd ..

docker build -f Dockerfile.prophet-32 -t prophet-1.0-multi-base

docker build -f Dockerfile.cgc-prophet-32 -t cgc-pr-tr:latest
