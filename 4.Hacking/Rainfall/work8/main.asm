Dump of assembler code for function main:
   0x08048564 <+0>:     push   %ebp
   0x08048565 <+1>:     mov    %esp,%ebp
   0x08048567 <+3>:     push   %edi
   0x08048568 <+4>:     push   %esi
   0x08048569 <+5>:     and    $0xfffffff0,%esp
   0x0804856c <+8>:     sub    $0xa0,%esp
   0x08048572 <+14>:    jmp    0x8048575 <main+17>
   0x08048574 <+16>:    nop
   0x08048575 <+17>:    mov    0x8049ab0,%ecx					; 0x8049ab0 <service>
   0x0804857b <+23>:    mov    0x8049aac,%edx					; 0x8049aac <auth>
   0x08048581 <+29>:    mov    $0x8048810,%eax					; "%p, %p \n"
   0x08048586 <+34>:    mov    %ecx,0x8(%esp)
   0x0804858a <+38>:    mov    %edx,0x4(%esp)
   0x0804858e <+42>:    mov    %eax,(%esp)
   0x08048591 <+45>:    call   0x8048410 <printf@plt>			; call <printf@plt>
   0x08048596 <+50>:    mov    0x8049a80,%eax					; <stdin@@GLIBC_2.0>
   0x0804859b <+55>:    mov    %eax,0x8(%esp)
   0x0804859f <+59>:    movl   $0x80,0x4(%esp)					; 128
   0x080485a7 <+67>:    lea    0x20(%esp),%eax
   0x080485ab <+71>:    mov    %eax,(%esp)
   0x080485ae <+74>:    call   0x8048440 <fgets@plt>			; call <fgets@plt>
   0x080485b3 <+79>:    test   %eax,%eax
   0x080485b5 <+81>:    je     0x804872c <main+456>
   0x080485bb <+87>:    lea    0x20(%esp),%eax
   0x080485bf <+91>:    mov    %eax,%edx
   0x080485c1 <+93>:    mov    $0x8048819,%eax					; "auth "
   0x080485c6 <+98>:    mov    $0x5,%ecx
   0x080485cb <+103>:   mov    %edx,%esi
   0x080485cd <+105>:   mov    %eax,%edi
   0x080485cf <+107>:   repz cmpsb %es:(%edi),%ds:(%esi)
   0x080485d1 <+109>:   seta   %dl
   0x080485d4 <+112>:   setb   %al
   0x080485d7 <+115>:   mov    %edx,%ecx
   0x080485d9 <+117>:   sub    %al,%cl
   0x080485db <+119>:   mov    %ecx,%eax
   0x080485dd <+121>:   movsbl %al,%eax
   0x080485e0 <+124>:   test   %eax,%eax
   0x080485e2 <+126>:   jne    0x8048642 <main+222>
   0x080485e4 <+128>:   movl   $0x4,(%esp)
   0x080485eb <+135>:   call   0x8048470 <malloc@plt>			; call <malloc@plt>
   0x080485f0 <+140>:   mov    %eax,0x8049aac					; 0x8049aac <auth>
   0x080485f5 <+145>:   mov    0x8049aac,%eax					; 0x8049aac <auth>
   0x080485fa <+150>:   movl   $0x0,(%eax)
   0x08048600 <+156>:   lea    0x20(%esp),%eax
   0x08048604 <+160>:   add    $0x5,%eax
   0x08048607 <+163>:   movl   $0xffffffff,0x1c(%esp)			; int max (4294967295)
   0x0804860f <+171>:   mov    %eax,%edx
   0x08048611 <+173>:   mov    $0x0,%eax
   0x08048616 <+178>:   mov    0x1c(%esp),%ecx
   0x0804861a <+182>:   mov    %edx,%edi
   0x0804861c <+184>:   repnz scas %es:(%edi),%al
   0x0804861e <+186>:   mov    %ecx,%eax
   0x08048620 <+188>:   not    %eax
   0x08048622 <+190>:   sub    $0x1,%eax
   0x08048625 <+193>:   cmp    $0x1e,%eax						; 30
   0x08048628 <+196>:   ja     0x8048642 <main+222>
   0x0804862a <+198>:   lea    0x20(%esp),%eax
   0x0804862e <+202>:   lea    0x5(%eax),%edx
   0x08048631 <+205>:   mov    0x8049aac,%eax					; 0x8049aac <auth>
   0x08048636 <+210>:   mov    %edx,0x4(%esp)
   0x0804863a <+214>:   mov    %eax,(%esp)
   0x0804863d <+217>:   call   0x8048460 <strcpy@plt>			; call <strcpy@plt>
   0x08048642 <+222>:   lea    0x20(%esp),%eax
   0x08048646 <+226>:   mov    %eax,%edx
   0x08048648 <+228>:   mov    $0x804881f,%eax					; "reset"
   0x0804864d <+233>:   mov    $0x5,%ecx
   0x08048652 <+238>:   mov    %edx,%esi
   0x08048654 <+240>:   mov    %eax,%edi
   0x08048656 <+242>:   repz cmpsb %es:(%edi),%ds:(%esi)
   0x08048658 <+244>:   seta   %dl
   0x0804865b <+247>:   setb   %al
   0x0804865e <+250>:   mov    %edx,%ecx
   0x08048660 <+252>:   sub    %al,%cl
   0x08048662 <+254>:   mov    %ecx,%eax
   0x08048664 <+256>:   movsbl %al,%eax
   0x08048667 <+259>:   test   %eax,%eax
   0x08048669 <+261>:   jne    0x8048678 <main+276>
   0x0804866b <+263>:   mov    0x8049aac,%eax					; 0x8049aac <auth>
   0x08048670 <+268>:   mov    %eax,(%esp)
   0x08048673 <+271>:   call   0x8048420 <free@plt>				; call <free@plt>
   0x08048678 <+276>:   lea    0x20(%esp),%eax
   0x0804867c <+280>:   mov    %eax,%edx
   0x0804867e <+282>:   mov    $0x8048825,%eax					; "service"
   0x08048683 <+287>:   mov    $0x6,%ecx
   0x08048688 <+292>:   mov    %edx,%esi
   0x0804868a <+294>:   mov    %eax,%edi
   0x0804868c <+296>:   repz cmpsb %es:(%edi),%ds:(%esi)
   0x0804868e <+298>:   seta   %dl
   0x08048691 <+301>:   setb   %al
   0x08048694 <+304>:   mov    %edx,%ecx
   0x08048696 <+306>:   sub    %al,%cl
   0x08048698 <+308>:   mov    %ecx,%eax
   0x0804869a <+310>:   movsbl %al,%eax
   0x0804869d <+313>:   test   %eax,%eax
   0x0804869f <+315>:   jne    0x80486b5 <main+337>
   0x080486a1 <+317>:   lea    0x20(%esp),%eax
   0x080486a5 <+321>:   add    $0x7,%eax						; buf + 7
   0x080486a8 <+324>:   mov    %eax,(%esp)
   0x080486ab <+327>:   call   0x8048430 <strdup@plt>			; call <strdup@plt>
   0x080486b0 <+332>:   mov    %eax,0x8049ab0					; 0x8049ab0 <service>
   0x080486b5 <+337>:   lea    0x20(%esp),%eax
   0x080486b9 <+341>:   mov    %eax,%edx
   0x080486bb <+343>:   mov    $0x804882d,%eax					; "login"
   0x080486c0 <+348>:   mov    $0x5,%ecx
   0x080486c5 <+353>:   mov    %edx,%esi
   0x080486c7 <+355>:   mov    %eax,%edi
   0x080486c9 <+357>:   repz cmpsb %es:(%edi),%ds:(%esi)
   0x080486cb <+359>:   seta   %dl
   0x080486ce <+362>:   setb   %al
   0x080486d1 <+365>:   mov    %edx,%ecx
   0x080486d3 <+367>:   sub    %al,%cl
   0x080486d5 <+369>:   mov    %ecx,%eax
   0x080486d7 <+371>:   movsbl %al,%eax
   0x080486da <+374>:   test   %eax,%eax
   0x080486dc <+376>:   jne    0x8048574 <main+16>
   0x080486e2 <+382>:   mov    0x8049aac,%eax					; 0x8049aac <auth>
   0x080486e7 <+387>:   mov    0x20(%eax),%eax
   0x080486ea <+390>:   test   %eax,%eax
   0x080486ec <+392>:   je     0x80486ff <main+411>
   0x080486ee <+394>:   movl   $0x8048833,(%esp)				; "/bin/sh"
   0x080486f5 <+401>:   call   0x8048480 <system@plt>			; call <system@plt>
   0x080486fa <+406>:   jmp    0x8048574 <main+16>
   0x080486ff <+411>:   mov    0x8049aa0,%eax					; <stdout@@GLIBC_2.0>
   0x08048704 <+416>:   mov    %eax,%edx
   0x08048706 <+418>:   mov    $0x804883b,%eax					; "Password:\n"
   0x0804870b <+423>:   mov    %edx,0xc(%esp)
   0x0804870f <+427>:   movl   $0xa,0x8(%esp)					; 10
   0x08048717 <+435>:   movl   $0x1,0x4(%esp)
   0x0804871f <+443>:   mov    %eax,(%esp)
   0x08048722 <+446>:   call   0x8048450 <fwrite@plt>			; call <fwrite@plt>
   0x08048727 <+451>:   jmp    0x8048574 <main+16>
   0x0804872c <+456>:   nop
   0x0804872d <+457>:   mov    $0x0,%eax
   0x08048732 <+462>:   lea    -0x8(%ebp),%esp
   0x08048735 <+465>:   pop    %esi
   0x08048736 <+466>:   pop    %edi
   0x08048737 <+467>:   pop    %ebp
   0x08048738 <+468>:   ret


08048564 <main>:
 8048572:       eb 01                   jmp    8048575 <main+0x11>
 8048591:       e8 7a fe ff ff          call   8048410 <printf@plt>
 80485ae:       e8 8d fe ff ff          call   8048440 <fgets@plt>
 80485b3:       85 c0                   test   %eax,%eax
 80485b5:       0f 84 71 01 00 00       je     804872c <main+0x1c8>
 80485cf:       f3 a6                   repz cmpsb %es:(%edi),%ds:(%esi)
 80485e0:       85 c0                   test   %eax,%eax
 80485e2:       75 5e                   jne    8048642 <main+0xde>
 80485eb:       e8 80 fe ff ff          call   8048470 <malloc@plt>
 8048625:       83 f8 1e                cmp    $0x1e,%eax
 8048628:       77 18                   ja     8048642 <main+0xde>
 804863d:       e8 1e fe ff ff          call   8048460 <strcpy@plt>					; <-------------- strcpy
 8048656:       f3 a6                   repz cmpsb %es:(%edi),%ds:(%esi)
 8048667:       85 c0                   test   %eax,%eax
 8048669:       75 0d                   jne    8048678 <main+0x114>
 8048673:       e8 a8 fd ff ff          call   8048420 <free@plt>					; <-------------- free
 804868c:       f3 a6                   repz cmpsb %es:(%edi),%ds:(%esi)
 804869d:       85 c0                   test   %eax,%eax
 804869f:       75 14                   jne    80486b5 <main+0x151>
 80486ab:       e8 80 fd ff ff          call   8048430 <strdup@plt>
 80486c9:       f3 a6                   repz cmpsb %es:(%edi),%ds:(%esi)
 80486da:       85 c0                   test   %eax,%eax
 80486dc:       0f 85 92 fe ff ff       jne    8048574 <main+0x10>
 80486ea:       85 c0                   test   %eax,%eax
 80486ec:       74 11                   je     80486ff <main+0x19b>
 80486f5:       e8 86 fd ff ff          call   8048480 <system@plt>					; <-------------- system
 80486fa:       e9 75 fe ff ff          jmp    8048574 <main+0x10>
 8048722:       e8 29 fd ff ff          call   8048450 <fwrite@plt>
 8048727:       e9 48 fe ff ff          jmp    8048574 <main+0x10>


08049aac <auth>:
 8049aac:	00 00                	add    %al,(%eax)
	...

08049ab0 <service>:
 8049ab0:	00 00                	add    %al,(%eax)
	...

(gdb) x 0x8049ab0		0x8049ab0 <service>:    0x00000000
(gdb) x 0x8049aac		0x8049aac <auth>:       0x00000000
(gdb) x/s 0x8048810		0x8048810:       		"%p, %p \n" 
(gdb) x/7s 0x8048819
	0x8048819:       "auth "
	0x804881f:       "reset"
	0x8048825:       "service"
	0x804882d:       "login"
	0x8048833:       "/bin/sh"
	0x804883b:       "Password:\n"
	0x8048846:       <Address 0x8048846 out of bounds>