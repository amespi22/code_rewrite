#!/bin/bash

MAX=$1
ID=0;
cur=0;
for F in $(ls -d /CGC/cgc_runs.test/scripts/transform.*.bash); do
  cnt=$(egrep -c 'prophet ' $F)
  curcnt=$(( $cnt+$cur ))
  if (( $curcnt>$MAX )); then (( ID+=1 )); cur=0; 
  else cur=$curcnt; fi
  
  if [[ ! -e transform-$ID.bash ]]; then 
   echo '#!/bin/bash' > trans-chunk-$ID.bash; chmod +x trans-chunk-$ID.bash; 
  fi
  echo $(realpath $F) >> trans-chunk-$ID.bash; 
done



ID=0;
cur=0;
for F in $(ls -d /CGC/cgc_runs.test/scripts/baseline.*.bash); do
  cnt=$(egrep -c 'prophet ' $F)
  curcnt=$(( $cnt+$cur ))
  if (( $curcnt>$MAX )); then (( ID+=1 )); cur=0; 
  else cur=$curcnt; fi
  
  if [[ ! -e baseline-$ID.bash ]]; then 
   echo '#!/bin/bash' > base-chunk-$ID.bash; chmod +x base-chunk-$ID.bash; 
  fi
  echo $(realpath $F) >> base-chunk-$ID.bash; 
done



