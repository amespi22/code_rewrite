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
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00002.xml
;;
p2)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00021.xml
;;
p3)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00025.xml
;;
p4)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00030.xml
;;
p5)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00039.xml
;;
p6)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00044.xml
;;
p7)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00058.xml
;;
p8)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00059.xml
;;
p9)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00061.xml
;;
p10)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00062.xml
;;
p11)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00063.xml
;;
p12)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00064.xml
;;
p13)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00065.xml
;;
p14)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00070.xml
;;
p15)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00079.xml
;;
p16)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00080.xml
;;
p17)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00088.xml
;;
p18)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00092.xml
;;
n1)
	./tools/cb-replay-pov.py --cbs $bin --timeout 5 --negotiate pov_2.pov

;;

esac

exit $?