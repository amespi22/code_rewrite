#!/bin/bash 
mkdir -p logs;

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-7 &> logs/gp.ga.7.0.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-7 &> logs/gp.ga.7.1.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-7 &> logs/gp.ga.7.2.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-7 &> logs/gp.ga.7.3.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-7 &> logs/gp.ga.7.4.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-7 &> logs/gp.ga.7.5.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-cf-gp-7 &> logs/gp.ga.7.6.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done
