#!/bin/bash

ME=`whoami`

IPCS_S=`ipcs -s | grep $ME | cut -d " " -f $1`
IPCS_M=`ipcs -m | grep $ME | cut -d " " -f $1`
IPCS_Q=`ipcs -q | grep $ME | cut -d " " -f $1`


for id in $IPCS_M; do
	ipcrm -m $id;
done

for id in $IPCS_S; do
	ipcrm -s $id;
done

for id in $IPCS_Q; do
	ipcrm -q $id;
done
