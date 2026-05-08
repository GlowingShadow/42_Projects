#!/bin/sh

i="-1040108899"

while [ $i -lt -1040108870 ]
do
        echo -n "$i    "
        (echo read; sleep 0.1 ; echo $i ; sleep 0.1 ; echo quit) | ./level07 | grep is
        i=$[$i+1]
done
