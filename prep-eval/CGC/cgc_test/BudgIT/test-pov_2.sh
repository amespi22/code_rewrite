#!/bin/bash

###################################################
# THIS SCRIPT HAS BEEN AUTOMATICALLY GENERATED BY
#          cgc_test_setup.bash
###################################################


# $1 = EXE
# $2 = test name
# $3 = port
# $4 = source name
# $5 = single-fitness-file name
# exit 0 = success
bin=$1
tst=$2
#trap 'kill $(jobs -p)' EXIT
#exe="setarch $(uname -m) -R $bin"

export ENABLE_FIXES=1
export LD_BIND_NOW=1


case $tst in

p1)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00003.xml
;;
p2)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00041.xml
;;
p3)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00053.xml
;;
p4)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00054.xml
;;
p5)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00055.xml
;;
p6)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00057.xml
;;
p7)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00059.xml
;;
p8)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00084.xml
;;
p9)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00099.xml
;;
n1)
	./tools/cb-replay-pov.py --cbs $bin --timeout 5 --negotiate pov_2.pov
;;
esac

exit $?