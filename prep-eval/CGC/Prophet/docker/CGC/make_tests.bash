#!/bin/bash

MAX=$1
tot=$(ls -d /CGC/cgc_runs.test/scripts/transform.*.bash | wc -l); 
echo '#!/bin/bash' > transform.bash; chmod +x transform.bash; 
ls -d /CGC/cgc_runs.test/scripts/transform.*.bash  >> transform.bash; 
for ID in $(seq 1 $MAX); do echo '#!/bin/bash' > transform-$ID.bash; chmod +x transform-$ID.bash; done; 
ID=$MAX;
for F in $(ls -d /CGC/cgc_runs.test/scripts/transform.*.bash); do
(( ID+=1 )); if (( $ID>$MAX )); then ID=1; fi; 
echo $(realpath $F) >> transform-$ID.bash; 
done



tot=$(ls -d /CGC/cgc_runs.test/scripts/baseline.*.bash | wc -l); 
echo '#!/bin/bash' > baseline.bash; chmod +x baseline.bash ;
ls -d /CGC/cgc_runs.test/scripts/baseline.*.bash  >> baseline.bash; 
for ID in $(seq 1 $MAX); do echo '#!/bin/bash' > baseline-$ID.bash; chmod +x baseline-$ID.bash; done; 
ID=$MAX;
for F in $(ls -d /CGC/cgc_runs.test/scripts/baseline.*.bash); do
(( ID+=1 )); if (( $ID>$MAX )); then ID=1; fi; 
echo $(realpath $F) >> baseline-$ID.bash; 
done




