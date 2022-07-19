#!/bin/bash
export PROPHET64_BASE=/PROPHET/prophet/prophet-gpl
cd /CGC/cgc_runs.test
mkdir -p logs/Movie_Rental_Service runs/Movie_Rental_Service; curdir=$(pwd); pushd runs/Movie_Rental_Service > /dev/null
timeout -k 8h 8h ${PROPHET64_BASE}/src/prophet /CGC/cgc_cfgs.test/Movie_Rental_Service/transform.Movie_Rental_Service.pov_1.conf -r transform.Movie_Rental_Service.pov_1  >& $curdir/logs/Movie_Rental_Service/transform.Movie_Rental_Service.pov_1.log
popd > /dev/null; echo "Done - Movie_Rental_Service"
