#!/usr/bin/env bash

export CODEFLAWS_BASE=$PWD
git clone https://github.com/codeflaws/codeflaws.git codeflaws_repo
wget http://www.comp.nus.edu.sg/~release/codeflaws/codeflaws.tar.gz
tar xvzf codeflaws.tar.gz
cp -r codeflaws codeflaws-trans
cp $CODEFLAWS_BASE/transform.bash codeflaws-trans/
cp run-version-prophet-trans.sh codeflaws_repo/all-script/

pushd codeflaws-trans
./transform.bash
popd


echo -e "Hello user! \nThe Codeflaws repo requires you to locally install a number of APR tools to use them."
echo -e "NOTE::  Please make sure you update \'run-version*.sh\' scripts to account for these tool paths"
echo -e "This includes our \'run-version-prophet-trans.sh\' script that's been copied into the \'codeflaws-trans\' directory"
