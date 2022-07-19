#!/bin/bash 
mkdir -p logs;

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-6 &> logs/gp.ga.6.0.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-6 &> logs/gp.ga.6.1.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-6 &> logs/gp.ga.6.2.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-6 &> logs/gp.ga.6.3.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-6 &> logs/gp.ga.6.4.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-6 &> logs/gp.ga.6.5.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done

timeout -k 8h 8h /usr/bin/genprog cfg-gp-6 &> logs/gp.ga.6.6.log

for x in $(ls -d xform/t_*.c); do y=$(echo $x | sed 's#xform/t_##'); cp $x CGC_Planet_Markup_Language_Parser/src/CGC_Planet_Markup_Language_Parser/src/$y; done
