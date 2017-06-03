#!/bin/bash
echo 5000
for i in {1..5000}
do
   echo $(($RANDOM%61000-30000)) $(($RANDOM%61000-30000)) $(($RANDOM%61000-30000)) $RANDOM
done
