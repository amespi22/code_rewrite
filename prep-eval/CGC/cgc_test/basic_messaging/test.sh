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
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00005.xml
;;
p2)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00006.xml
;;
p3)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00007.xml
;;
p4)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00011.xml
;;
p5)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00015.xml
;;
p6)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00016.xml
;;
p7)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00017.xml
;;
p8)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00018.xml
;;
p9)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00019.xml
;;
p10)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00020.xml
;;
p11)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00021.xml
;;
p12)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00022.xml
;;
p13)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00027.xml
;;
p14)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00028.xml
;;
p15)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00030.xml
;;
p16)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00034.xml
;;
p17)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00038.xml
;;
p18)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00039.xml
;;
p19)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00040.xml
;;
p20)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00041.xml
;;
p21)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00045.xml
;;
p22)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00047.xml
;;
p23)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00048.xml
;;
p24)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00049.xml
;;
p25)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00057.xml
;;
p26)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00060.xml
;;
p27)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00063.xml
;;
p28)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00064.xml
;;
p29)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00066.xml
;;
p30)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00068.xml
;;
p31)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00069.xml
;;
p32)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00070.xml
;;
p33)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00071.xml
;;
p34)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00075.xml
;;
p35)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00080.xml
;;
p36)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00081.xml
;;
p37)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00082.xml
;;
p38)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00083.xml
;;
p39)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00086.xml
;;
p40)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00088.xml
;;
p41)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00089.xml
;;
p42)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00091.xml
;;
p43)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00094.xml
;;
p44)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00095.xml
;;
p45)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00099.xml
;;
p46)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00100.xml
;;
p47)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00101.xml
;;
p48)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00103.xml
;;
p49)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00106.xml
;;
p50)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00107.xml
;;
p51)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00109.xml
;;
p52)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00110.xml
;;
p53)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00111.xml
;;
p54)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00112.xml
;;
p55)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00113.xml
;;
p56)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00114.xml
;;
p57)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00115.xml
;;
p58)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00116.xml
;;
p59)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00117.xml
;;
p60)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00120.xml
;;
p61)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00123.xml
;;
p62)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00125.xml
;;
p63)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00126.xml
;;
p64)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00127.xml
;;
p65)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00130.xml
;;
p66)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00131.xml
;;
p67)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00133.xml
;;
p68)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00134.xml
;;
p69)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00136.xml
;;
p70)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00140.xml
;;
p71)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00146.xml
;;
p72)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00148.xml
;;
p73)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00149.xml
;;
p74)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00150.xml
;;
p75)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00151.xml
;;
p76)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00153.xml
;;
p77)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00155.xml
;;
p78)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00156.xml
;;
p79)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00157.xml
;;
p80)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00159.xml
;;
p81)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00161.xml
;;
p82)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00162.xml
;;
p83)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00163.xml
;;
p84)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00165.xml
;;
p85)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00166.xml
;;
p86)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00170.xml
;;
p87)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00171.xml
;;
p88)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00174.xml
;;
p89)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00176.xml
;;
p90)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00177.xml
;;
p91)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00181.xml
;;
p92)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00182.xml
;;
p93)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00189.xml
;;
p94)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00191.xml
;;
p95)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00192.xml
;;
p96)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00195.xml
;;
p97)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00200.xml
;;
p98)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00202.xml
;;
p99)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00203.xml
;;
p100)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00205.xml
;;
p101)
	./tools/cb-replay.py --cbs $bin --timeout 5 --negotiate ./poller/cb-for-release/POLL_00214.xml
;;
#n1)
#	./tools/cb-test.py --cb $bin --timeout 5 --negotiate --directory ./ --xml_dir ./ --concurrent 4
#;;
n1)
	./tools/cb-replay-pov.py --cbs $bin --timeout 5 --negotiate pov_1.pov

;;

esac

exit $?
