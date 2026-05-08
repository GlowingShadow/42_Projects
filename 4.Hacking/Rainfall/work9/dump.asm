```Dump of assembler code for function _Znwj:								=	operator new ()
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
   0xb7f9b622 <+34>:    call   0xb7f34f60 <malloc@plt>			; call malloc
   0xb7f9b627 <+39>:    test   %eax,%eax
   0xb7f9b629 <+41>:    jne    0xb7f9b680 <_Znwj+128>
   0xb7f9b62b <+43>:    mov    -0x264(%ebx),%edi
   0xb7f9b631 <+49>:    mov    (%edi),%eax
   0xb7f9b633 <+51>:    test   %eax,%eax
   0xb7f9b635 <+53>:    je     0xb7f9b64c <_Znwj+76>
   0xb7f9b637 <+55>:    nop
   0xb7f9b638 <+56>:    call   *%eax
   0xb7f9b63a <+58>:    mov    %esi,(%esp)
   0xb7f9b63d <+61>:    call   0xb7f34f60 <malloc@plt>			; call malloc
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
   0x080486fc <+6>:     movl   $0x8048848,(%eax)
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
   0x0804871a <+12>:    call   0x8048520 <strlen@plt>
   0x0804871f <+17>:    mov    0x8(%ebp),%edx
   0x08048722 <+20>:    add    $0x4,%edx
   0x08048725 <+23>:    mov    %eax,0x8(%esp)
   0x08048729 <+27>:    mov    0xc(%ebp),%eax
   0x0804872c <+30>:    mov    %eax,0x4(%esp)
   0x08048730 <+34>:    mov    %edx,(%esp)
   0x08048733 <+37>:    call   0x8048510 <memcpy@plt>
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
   0x08048693 <+159>:   call   *%edx
   0x08048695 <+161>:   mov    -0x4(%ebp),%ebx
   0x08048698 <+164>:   leave
   0x08048699 <+165>:   ret
```