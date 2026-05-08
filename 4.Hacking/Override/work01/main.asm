level01`verify_user_name:
level01[0x8048464] <+0>:  pushl  %ebp
level01[0x8048465] <+1>:  movl   %esp, %ebp
level01[0x8048467] <+3>:  pushl  %edi
level01[0x8048468] <+4>:  pushl  %esi
level01[0x8048469] <+5>:  subl   $0x10, %esp
level01[0x804846c] <+8>:  movl   $0x8048690, (%esp)        ; imm = 0x8048690		"verifying username....\n"
level01[0x8048473] <+15>: calll  0x8048380                 ; symbol stub for: puts
level01[0x8048478] <+20>: movl   $0x804a040, %edx          ; imm = 0x804A040		<a_user_name>
level01[0x804847d] <+25>: movl   $0x80486a8, %eax          ; imm = 0x80486A8		"dat_wil"
level01[0x8048482] <+30>: movl   $0x7, %ecx
level01[0x8048487] <+35>: movl   %edx, %esi
level01[0x8048489] <+37>: movl   %eax, %edi
level01[0x804848b] <+39>: rep
level01[0x804848c] <+40>: cmpsb  %es:(%edi), (%esi)
level01[0x804848d] <+41>: seta   %dl
level01[0x8048490] <+44>: setb   %al
level01[0x8048493] <+47>: movl   %edx, %ecx
level01[0x8048495] <+49>: subb   %al, %cl
level01[0x8048497] <+51>: movl   %ecx, %eax
level01[0x8048499] <+53>: movsbl %al, %eax
level01[0x804849c] <+56>: addl   $0x10, %esp
level01[0x804849f] <+59>: popl   %esi
level01[0x80484a0] <+60>: popl   %edi
level01[0x80484a1] <+61>: popl   %ebp
level01[0x80484a2] <+62>: retl

level01`verify_user_pass:
level01[0x80484a3] <+0>:  pushl  %ebp
level01[0x80484a4] <+1>:  movl   %esp, %ebp
level01[0x80484a6] <+3>:  pushl  %edi
level01[0x80484a7] <+4>:  pushl  %esi
level01[0x80484a8] <+5>:  movl   0x8(%ebp), %eax
level01[0x80484ab] <+8>:  movl   %eax, %edx
level01[0x80484ad] <+10>: movl   $0x80486b0, %eax          ; imm = 0x80486B0		"admin"
level01[0x80484b2] <+15>: movl   $0x5, %ecx
level01[0x80484b7] <+20>: movl   %edx, %esi
level01[0x80484b9] <+22>: movl   %eax, %edi
level01[0x80484bb] <+24>: rep
level01[0x80484bc] <+25>: cmpsb  %es:(%edi), (%esi)
level01[0x80484bd] <+26>: seta   %dl
level01[0x80484c0] <+29>: setb   %al
level01[0x80484c3] <+32>: movl   %edx, %ecx
level01[0x80484c5] <+34>: subb   %al, %cl
level01[0x80484c7] <+36>: movl   %ecx, %eax
level01[0x80484c9] <+38>: movsbl %al, %eax
level01[0x80484cc] <+41>: popl   %esi
level01[0x80484cd] <+42>: popl   %edi
level01[0x80484ce] <+43>: popl   %ebp
level01[0x80484cf] <+44>: retl

level01`main:
level01[0x80484d0] <+0>:   pushl  %ebp
level01[0x80484d1] <+1>:   movl   %esp, %ebp
level01[0x80484d3] <+3>:   pushl  %edi
level01[0x80484d4] <+4>:   pushl  %ebx
level01[0x80484d5] <+5>:   andl   $-0x10, %esp				; 16
level01[0x80484d8] <+8>:   subl   $0x60, %esp				; 96
level01[0x80484db] <+11>:  leal   0x1c(%esp), %ebx			; 28
level01[0x80484df] <+15>:  movl   $0x0, %eax
level01[0x80484e4] <+20>:  movl   $0x10, %edx				; 16
level01[0x80484e9] <+25>:  movl   %ebx, %edi
level01[0x80484eb] <+27>:  movl   %edx, %ecx
level01[0x80484ed] <+29>:  rep
level01[0x80484ee] <+30>:  stosl  %eax, %es:(%edi)
level01[0x80484ef] <+31>:  movl   $0x0, 0x5c(%esp)
level01[0x80484f7] <+39>:  movl   $0x80486b8, (%esp)        ; imm = 0x80486B8			"********* ADMIN LOGIN PROMPT *********"
level01[0x80484fe] <+46>:  calll  0x8048380                 ; symbol stub for: puts
level01[0x8048503] <+51>:  movl   $0x80486df, %eax          ; imm = 0x80486DF			"Enter Username: "
level01[0x8048508] <+56>:  movl   %eax, (%esp)
level01[0x804850b] <+59>:  calll  0x8048360                 ; symbol stub for: printf
level01[0x8048510] <+64>:  movl   0x804a020, %eax
level01[0x8048515] <+69>:  movl   %eax, 0x8(%esp)
level01[0x8048519] <+73>:  movl   $0x100, 0x4(%esp)         ; imm = 0x100	256
level01[0x8048521] <+81>:  movl   $0x804a040, (%esp)        ; imm = 0x804A040			<a_user_name>
level01[0x8048528] <+88>:  calll  0x8048370                 ; symbol stub for: fgets
level01[0x804852d] <+93>:  calll  0x8048464                 ; verify_user_name
level01[0x8048532] <+98>:  movl   %eax, 0x5c(%esp)
level01[0x8048536] <+102>: cmpl   $0x0, 0x5c(%esp)
level01[0x804853b] <+107>: je     0x8048550                 ; <+128>
level01[0x804853d] <+109>: movl   $0x80486f0, (%esp)        ; imm = 0x80486F0			"nope, incorrect username...\n"
level01[0x8048544] <+116>: calll  0x8048380                 ; symbol stub for: puts
level01[0x8048549] <+121>: movl   $0x1, %eax
level01[0x804854e] <+126>: jmp    0x80485af                 ; <+223>
level01[0x8048550] <+128>: movl   $0x804870d, (%esp)        ; imm = 0x804870D			"Enter Password: "
level01[0x8048557] <+135>: calll  0x8048380                 ; symbol stub for: puts
level01[0x804855c] <+140>: movl   0x804a020, %eax
level01[0x8048561] <+145>: movl   %eax, 0x8(%esp)
level01[0x8048565] <+149>: movl   $0x64, 0x4(%esp)			;	100
level01[0x804856d] <+157>: leal   0x1c(%esp), %eax
level01[0x8048571] <+161>: movl   %eax, (%esp)
level01[0x8048574] <+164>: calll  0x8048370                 ; symbol stub for: fgets
level01[0x8048579] <+169>: leal   0x1c(%esp), %eax
level01[0x804857d] <+173>: movl   %eax, (%esp)
level01[0x8048580] <+176>: calll  0x80484a3                 ; verify_user_pass
level01[0x8048585] <+181>: movl   %eax, 0x5c(%esp)
level01[0x8048589] <+185>: cmpl   $0x0, 0x5c(%esp)
level01[0x804858e] <+190>: je     0x8048597                 ; <+199>
level01[0x8048590] <+192>: cmpl   $0x0, 0x5c(%esp)
level01[0x8048595] <+197>: je     0x80485aa                 ; <+218>
level01[0x8048597] <+199>: movl   $0x804871e, (%esp)        ; imm = 0x804871E			"nope, incorrect password...\n"
level01[0x804859e] <+206>: calll  0x8048380                 ; symbol stub for: puts
level01[0x80485a3] <+211>: movl   $0x1, %eax
level01[0x80485a8] <+216>: jmp    0x80485af                 ; <+223>
level01[0x80485aa] <+218>: movl   $0x0, %eax
level01[0x80485af] <+223>: leal   -0x8(%ebp), %esp
level01[0x80485b2] <+226>: popl   %ebx
level01[0x80485b3] <+227>: popl   %edi
level01[0x80485b4] <+228>: popl   %ebp
level01[0x80485b5] <+229>: retl