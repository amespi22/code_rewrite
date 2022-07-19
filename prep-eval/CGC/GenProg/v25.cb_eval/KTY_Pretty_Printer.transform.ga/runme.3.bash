#!/bin/bash 
mkdir -p logs;

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x KTY_Pretty_Printer/src/KTY_Pretty_Printer/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-3 &> logs/gp.ga.3.0.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x KTY_Pretty_Printer/src/KTY_Pretty_Printer/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-3 &> logs/gp.ga.3.1.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x KTY_Pretty_Printer/src/KTY_Pretty_Printer/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-3 &> logs/gp.ga.3.2.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x KTY_Pretty_Printer/src/KTY_Pretty_Printer/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-3 &> logs/gp.ga.3.3.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x KTY_Pretty_Printer/src/KTY_Pretty_Printer/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-3 &> logs/gp.ga.3.4.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x KTY_Pretty_Printer/src/KTY_Pretty_Printer/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-3 &> logs/gp.ga.3.5.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x KTY_Pretty_Printer/src/KTY_Pretty_Printer/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-3 &> logs/gp.ga.3.6.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x KTY_Pretty_Printer/src/KTY_Pretty_Printer/src/$y; done
