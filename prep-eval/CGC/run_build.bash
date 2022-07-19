#!/usr/bin/env bash


for cb in $(cat ./cb_eval.c_xlist); do
   for cbdir in $(ls -d GenProg/v25.cb_eval/${cb}* ); do
      mkdir $cbdir/$cb/build; pushd $cbdir/$cb/build;
        cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
        -DCMAKE_VERBOSE_MAKEFILE=ON \
        -DBUILD_SHARED_LIBS=ON \
        -DBUILD_STATIC_LIBS=OFF \
        -DCMAKE_C_COMPILER=gcc-8 \
        -DCMAKE_ASM_COMPILER=gcc-8 \
        -DCMAKE_CXX_COMPILER=g++-8 \
        -DBINARY=$cb \
        -DPATCHED=OFF \
        ../src &> cfg.log
      make &> build.log
      popd
   done
done
