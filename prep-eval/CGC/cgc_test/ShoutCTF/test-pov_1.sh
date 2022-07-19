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
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00000.xml
;;
p2)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00001.xml
;;
p3)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00003.xml
;;
p4)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00004.xml
;;
p5)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00005.xml
;;
p6)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00006.xml
;;
p7)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00007.xml
;;
p8)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00008.xml
;;
p9)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00009.xml
;;
p10)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00010.xml
;;
p11)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00012.xml
;;
p12)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00013.xml
;;
p13)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00014.xml
;;
p14)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00015.xml
;;
p15)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00016.xml
;;
p16)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00017.xml
;;
p17)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00018.xml
;;
p18)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00022.xml
;;
p19)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00023.xml
;;
p20)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00026.xml
;;
p21)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00027.xml
;;
p22)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00028.xml
;;
p23)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00029.xml
;;
p24)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00030.xml
;;
p25)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00031.xml
;;
p26)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00032.xml
;;
p27)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00033.xml
;;
p28)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00034.xml
;;
p29)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00035.xml
;;
p30)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00036.xml
;;
p31)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00037.xml
;;
p32)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00038.xml
;;
p33)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00040.xml
;;
p34)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00041.xml
;;
p35)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00042.xml
;;
p36)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00043.xml
;;
p37)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00044.xml
;;
p38)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00045.xml
;;
p39)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00046.xml
;;
p40)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00048.xml
;;
p41)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00050.xml
;;
p42)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00051.xml
;;
p43)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00052.xml
;;
p44)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00053.xml
;;
p45)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00056.xml
;;
p46)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00057.xml
;;
p47)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00058.xml
;;
p48)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00059.xml
;;
p49)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00060.xml
;;
p50)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00062.xml
;;
p51)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00063.xml
;;
p52)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00064.xml
;;
p53)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00066.xml
;;
p54)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00067.xml
;;
p55)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00068.xml
;;
p56)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00069.xml
;;
p57)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00070.xml
;;
p58)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00071.xml
;;
p59)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00072.xml
;;
p60)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00073.xml
;;
p61)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00075.xml
;;
p62)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00077.xml
;;
p63)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00078.xml
;;
p64)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00079.xml
;;
p65)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00080.xml
;;
p66)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00081.xml
;;
p67)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00083.xml
;;
p68)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00084.xml
;;
p69)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00085.xml
;;
p70)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00086.xml
;;
p71)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00087.xml
;;
p72)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00089.xml
;;
p73)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00090.xml
;;
p74)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00091.xml
;;
p75)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00092.xml
;;
p76)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00093.xml
;;
p77)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00094.xml
;;
p78)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00095.xml
;;
p79)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00096.xml
;;
p80)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00097.xml
;;
p81)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00098.xml
;;
p82)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/for-release/GEN_00000_00099.xml
;;
n1)
	./tools/cb-replay-pov.py --cbs $bin --timeout 5 --negotiate pov_1.pov
;;
esac

exit $?
