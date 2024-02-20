#!/usr/bin/env bash

if [[ -z $CODE_EXPAND_PATH ]]; then
  echo "Looks like \$CODE_EXPAND_PATH isn't set."
  echo "Please set this ENV variable to directory where `code_expand.py` exists"
  echo "This is usually set up in the root directory of this repo with `set_env.sh`"
  return 0;
fi

export CODEFLAWS_BASE=$PWD

git clone https://github.com/codeflaws/codeflaws.git codeflaws_repo
wget -c http://www.comp.nus.edu.sg/~release/codeflaws/codeflaws.tar.gz
tar xvzf codeflaws.tar.gz
cp -r json_input codeflaws/
cp -r codeflaws codeflaws-trans
cp $CODEFLAWS_BASE/transform.bash codeflaws-trans/

pushd codeflaws-trans
./transform.bash
popd

#copying run scripts that allow for baseline and transform testing
cp run-version-*.sh codeflaws_repo/all-script/
cp validate-fix-*.sh codeflaws_repo/all-script/


echo -e "Hello user! \nThe Codeflaws repo requires you to locally install a number of APR tools to use them."
echo -e "NOTE::  Please make sure you update \'run-version*.sh\' scripts to account for these tool paths"
echo -e "This includes our \'run-version-prophet*.sh\' scripts that have been copied into the \'codeflaws_repo/all-script\' directory"
