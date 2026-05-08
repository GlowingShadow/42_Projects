#!/bin/sh

a=10

while [ a > 0 ]
do
	make
	echo $a
	sleep 1
	a=`expr $a + 1`
done
