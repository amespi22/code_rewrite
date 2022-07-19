#!/bin/bash 
mkdir -p logs;

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x Minimalistic_Memo_Manager_3M/src/Minimalistic_Memo_Manager_3M/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-1 &> logs/gp.ga.1.0.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x Minimalistic_Memo_Manager_3M/src/Minimalistic_Memo_Manager_3M/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-1 &> logs/gp.ga.1.1.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x Minimalistic_Memo_Manager_3M/src/Minimalistic_Memo_Manager_3M/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-1 &> logs/gp.ga.1.2.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x Minimalistic_Memo_Manager_3M/src/Minimalistic_Memo_Manager_3M/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-1 &> logs/gp.ga.1.3.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x Minimalistic_Memo_Manager_3M/src/Minimalistic_Memo_Manager_3M/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-1 &> logs/gp.ga.1.4.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x Minimalistic_Memo_Manager_3M/src/Minimalistic_Memo_Manager_3M/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-1 &> logs/gp.ga.1.5.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x Minimalistic_Memo_Manager_3M/src/Minimalistic_Memo_Manager_3M/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-1 &> logs/gp.ga.1.6.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x Minimalistic_Memo_Manager_3M/src/Minimalistic_Memo_Manager_3M/src/$y; done
