#!/bin/bash 
mkdir -p logs;

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x FablesReport/src/FablesReport/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-5 &> logs/gp.ga.5.0.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x FablesReport/src/FablesReport/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-5 &> logs/gp.ga.5.1.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x FablesReport/src/FablesReport/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-5 &> logs/gp.ga.5.2.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x FablesReport/src/FablesReport/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-5 &> logs/gp.ga.5.3.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x FablesReport/src/FablesReport/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-5 &> logs/gp.ga.5.4.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x FablesReport/src/FablesReport/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-5 &> logs/gp.ga.5.5.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x FablesReport/src/FablesReport/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-5 &> logs/gp.ga.5.6.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x FablesReport/src/FablesReport/src/$y; done
