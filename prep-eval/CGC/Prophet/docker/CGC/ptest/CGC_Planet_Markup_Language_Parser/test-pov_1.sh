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
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00002.xml
;;
p2)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00003.xml
;;
p3)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00004.xml
;;
p4)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00005.xml
;;
p5)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00007.xml
;;
p6)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00008.xml
;;
p7)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00009.xml
;;
p8)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00010.xml
;;
p9)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00011.xml
;;
p10)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00015.xml
;;
p11)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00017.xml
;;
p12)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00019.xml
;;
p13)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00020.xml
;;
p14)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00021.xml
;;
p15)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00023.xml
;;
p16)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00024.xml
;;
p17)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00025.xml
;;
p18)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00026.xml
;;
p19)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00027.xml
;;
p20)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00028.xml
;;
p21)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00029.xml
;;
p22)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00033.xml
;;
p23)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00035.xml
;;
p24)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00036.xml
;;
p25)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00037.xml
;;
p26)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00038.xml
;;
p27)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00039.xml
;;
p28)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00040.xml
;;
p29)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00041.xml
;;
p30)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00042.xml
;;
p31)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00043.xml
;;
p32)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00044.xml
;;
p33)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00045.xml
;;
p34)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00046.xml
;;
p35)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00047.xml
;;
p36)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00050.xml
;;
p37)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00051.xml
;;
p38)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00052.xml
;;
p39)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00054.xml
;;
p40)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00056.xml
;;
p41)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00057.xml
;;
p42)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00059.xml
;;
p43)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00060.xml
;;
p44)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00061.xml
;;
p45)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00062.xml
;;
p46)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00063.xml
;;
p47)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00064.xml
;;
p48)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00065.xml
;;
p49)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00066.xml
;;
p50)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00067.xml
;;
p51)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00068.xml
;;
p52)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00069.xml
;;
p53)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00070.xml
;;
p54)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00071.xml
;;
p55)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00072.xml
;;
p56)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00073.xml
;;
p57)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00074.xml
;;
p58)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00076.xml
;;
p59)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00078.xml
;;
p60)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00080.xml
;;
p61)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00081.xml
;;
p62)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00083.xml
;;
p63)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00084.xml
;;
p64)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00086.xml
;;
p65)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00087.xml
;;
p66)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00088.xml
;;
p67)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00090.xml
;;
p68)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00091.xml
;;
p69)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00095.xml
;;
p70)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00096.xml
;;
p71)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00098.xml
;;
p72)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00100.xml
;;
p73)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00101.xml
;;
p74)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00102.xml
;;
p75)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00103.xml
;;
p76)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00105.xml
;;
p77)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00106.xml
;;
p78)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00107.xml
;;
p79)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00108.xml
;;
p80)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00109.xml
;;
p81)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00110.xml
;;
p82)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00112.xml
;;
p83)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00113.xml
;;
p84)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00114.xml
;;
p85)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00116.xml
;;
p86)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00118.xml
;;
p87)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00119.xml
;;
p88)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00120.xml
;;
p89)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00121.xml
;;
p90)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00122.xml
;;
p91)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00124.xml
;;
p92)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00125.xml
;;
p93)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00126.xml
;;
p94)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00129.xml
;;
p95)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00130.xml
;;
p96)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00131.xml
;;
p97)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00136.xml
;;
p98)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00137.xml
;;
p99)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00138.xml
;;
p100)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00139.xml
;;
p101)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00140.xml
;;
#n1)
	#./tools/cb-test.py --cb $bin --timeout 5 --negotiate --directory ./ --xml_dir ./ --concurrent 4
#;;
n1)
	./tools/cb-replay-pov.py --cbs $bin --timeout 5 --negotiate pov_1.pov
;;
esac

exit $?
