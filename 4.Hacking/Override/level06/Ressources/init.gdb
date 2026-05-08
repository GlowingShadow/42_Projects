#1 break and jump to avoid tampering check
b *0x080487bd
#2 break on cmp serial
b *0x08048866

run
#1
jump *0x080487ed
#2
x/a $ebp-0x10