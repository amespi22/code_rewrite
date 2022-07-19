#!/bin/bash 
mkdir -p logs;

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x SCUBA_Dive_Logging/src/SCUBA_Dive_Logging/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-2 &> logs/gp.ga.2.0.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x SCUBA_Dive_Logging/src/SCUBA_Dive_Logging/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-2 &> logs/gp.ga.2.1.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x SCUBA_Dive_Logging/src/SCUBA_Dive_Logging/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-2 &> logs/gp.ga.2.2.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x SCUBA_Dive_Logging/src/SCUBA_Dive_Logging/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-2 &> logs/gp.ga.2.3.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x SCUBA_Dive_Logging/src/SCUBA_Dive_Logging/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-2 &> logs/gp.ga.2.4.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x SCUBA_Dive_Logging/src/SCUBA_Dive_Logging/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-2 &> logs/gp.ga.2.5.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x SCUBA_Dive_Logging/src/SCUBA_Dive_Logging/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-2 &> logs/gp.ga.2.6.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x SCUBA_Dive_Logging/src/SCUBA_Dive_Logging/src/$y; done
