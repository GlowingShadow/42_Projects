clear ; make ; rm champs/fluttershy.cor ; ./asm champs/fluttershy.s
mv champs/fluttershy.cor champs/fluttershy.cor1
./real_asm champs/fluttershy.s
hexdump -vC champs/fluttershy.cor > them
hexdump -vC champs/fluttershy.cor1 > me
diff champs/fluttershy.cor*

#bee_gees
#bigzork
#fluttershy
#helltrain
#turtle
#zork
#test
