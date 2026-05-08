#!/bin/bash

# Donner les droit dans le dossier courant
chmod 777 ./
#installation de john the ripper
wget https://www.openwall.com/john/j/john-1.8.0.tar.xz
tar -xf john-1.8.0.tar.xz
cd ./john-1.8.0/src
make
make clean linux-x86-avx
cd ../run
# execution de john
./john /etc/passwd
#./john -show /etc/passwd
#option -show pour voir les passwords deja cracké