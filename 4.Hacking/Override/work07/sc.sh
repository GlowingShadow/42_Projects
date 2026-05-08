#!/bin/bash
echo start

i="-20"
w="0.01"

while [ $i -lt 0 ]
do
	echo -n "$i     "
	(echo read; sleep $w ; echo $i ; sleep $w ; echo quit) | ./level07 | grep "is"
	echo ""
	i=$[$i+1]
done
