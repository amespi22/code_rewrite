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

export LD_BIND_NOW=1


case $tst in

p1)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00000.xml
;;
p2)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00003.xml
;;
p3)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00004.xml
;;
p4)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00007.xml
;;
p5)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00009.xml
;;
p6)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00010.xml
;;
p7)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00011.xml
;;
p8)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00012.xml
;;
p9)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00014.xml
;;
p10)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00017.xml
;;
p11)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00018.xml
;;
p12)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00026.xml
;;
p13)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00028.xml
;;
p14)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00033.xml
;;
p15)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00034.xml
;;
p16)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00045.xml
;;
p17)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00046.xml
;;
p18)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00047.xml
;;
p19)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00051.xml
;;
p20)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00053.xml
;;
p21)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00057.xml
;;
p22)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00059.xml
;;
p23)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00060.xml
;;
p24)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00062.xml
;;
p25)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00063.xml
;;
p26)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00064.xml
;;
p27)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00074.xml
;;
p28)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00075.xml
;;
p29)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00076.xml
;;
p30)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00078.xml
;;
p31)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00079.xml
;;
p32)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00084.xml
;;
p33)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00085.xml
;;
p34)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00086.xml
;;
p35)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00090.xml
;;
p36)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00092.xml
;;
p37)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00097.xml
;;
p38)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-testing/GEN_00000_00099.xml
;;
n1)
	./tools/cb-replay-pov.py --cbs $bin --timeout 5 --negotiate pov_1.pov
;;
esac

exit $?
