
test1:	file format Mach-O 32-bit i386

Disassembly of section __TEXT,__text:
__text:
    1ea0:	55 	pushl	%ebp
    1ea1:	89 e5 	movl	%esp, %ebp
    1ea3:	83 ec 18 	subl	$24, %esp
    1ea6:	8b 45 08 	movl	8(%ebp), %eax
    1ea9:	89 45 fc 	movl	%eax, -4(%ebp)
    1eac:	8b 45 fc 	movl	-4(%ebp), %eax
    1eaf:	89 04 24 	movl	%eax, (%esp)
    1eb2:	e8 bd 00 00 00 	calll	189
    1eb7:	89 45 f8 	movl	%eax, -8(%ebp)
    1eba:	83 c4 18 	addl	$24, %esp
    1ebd:	5d 	popl	%ebp
    1ebe:	c3 	retl
    1ebf:	90 	nop
    1ec0:	55 	pushl	%ebp
    1ec1:	89 e5 	movl	%esp, %ebp
    1ec3:	57 	pushl	%edi
    1ec4:	56 	pushl	%esi
    1ec5:	81 ec 30 01 00 00 	subl	$304, %esp
    1ecb:	e8 00 00 00 00 	calll	0 <_main+0x10>
    1ed0:	58 	popl	%eax
    1ed1:	8b 4d 0c 	movl	12(%ebp), %ecx
    1ed4:	8b 55 08 	movl	8(%ebp), %edx
    1ed7:	8d b0 cc 00 00 00 	leal	204(%eax), %esi
    1edd:	c7 45 f4 00 00 00 00 	movl	$0, -12(%ebp)
    1ee4:	89 55 f0 	movl	%edx, -16(%ebp)
    1ee7:	89 4d ec 	movl	%ecx, -20(%ebp)
    1eea:	89 34 24 	movl	%esi, (%esp)
    1eed:	89 85 e8 fe ff ff 	movl	%eax, -280(%ebp)
    1ef3:	e8 7c 00 00 00 	calll	124
    1ef8:	b9 00 01 00 00 	movl	$256, %ecx
    1efd:	8b 95 e8 fe ff ff 	movl	-280(%ebp), %edx
    1f03:	8b b2 38 01 00 00 	movl	312(%edx), %esi
    1f09:	8d bd ec fe ff ff 	leal	-276(%ebp), %edi
    1f0f:	8b 36 	movl	(%esi), %esi
    1f11:	89 3c 24 	movl	%edi, (%esp)
    1f14:	c7 44 24 04 00 01 00 00 	movl	$256, 4(%esp)
    1f1c:	89 74 24 08 	movl	%esi, 8(%esp)
    1f20:	89 85 e4 fe ff ff 	movl	%eax, -284(%ebp)
    1f26:	89 8d e0 fe ff ff 	movl	%ecx, -288(%ebp)
    1f2c:	e8 3d 00 00 00 	calll	61
    1f31:	8d 8d ec fe ff ff 	leal	-276(%ebp), %ecx
    1f37:	89 0c 24 	movl	%ecx, (%esp)
    1f3a:	89 85 dc fe ff ff 	movl	%eax, -292(%ebp)
    1f40:	e8 5b ff ff ff 	calll	-165 <_vulnfunction>
    1f45:	8b 85 e8 fe ff ff 	movl	-280(%ebp), %eax
    1f4b:	8d 88 d4 00 00 00 	leal	212(%eax), %ecx
    1f51:	89 0c 24 	movl	%ecx, (%esp)
    1f54:	e8 1b 00 00 00 	calll	27
    1f59:	31 c9 	xorl	%ecx, %ecx
    1f5b:	89 85 d8 fe ff ff 	movl	%eax, -296(%ebp)
    1f61:	89 c8 	movl	%ecx, %eax
    1f63:	81 c4 30 01 00 00 	addl	$304, %esp
    1f69:	5e 	popl	%esi
    1f6a:	5f 	popl	%edi
    1f6b:	5d 	popl	%ebp
    1f6c:	c3 	retl

_vulnfunction:
    1ea0:	55 	pushl	%ebp
    1ea1:	89 e5 	movl	%esp, %ebp
    1ea3:	83 ec 18 	subl	$24, %esp
    1ea6:	8b 45 08 	movl	8(%ebp), %eax
    1ea9:	89 45 fc 	movl	%eax, -4(%ebp)
    1eac:	8b 45 fc 	movl	-4(%ebp), %eax
    1eaf:	89 04 24 	movl	%eax, (%esp)
    1eb2:	e8 bd 00 00 00 	calll	189
    1eb7:	89 45 f8 	movl	%eax, -8(%ebp)
    1eba:	83 c4 18 	addl	$24, %esp
    1ebd:	5d 	popl	%ebp
    1ebe:	c3 	retl
    1ebf:	90 	nop

_main:
    1ec0:	55 	pushl	%ebp
    1ec1:	89 e5 	movl	%esp, %ebp
    1ec3:	57 	pushl	%edi
    1ec4:	56 	pushl	%esi
    1ec5:	81 ec 30 01 00 00 	subl	$304, %esp
    1ecb:	e8 00 00 00 00 	calll	0 <_main+0x10>
    1ed0:	58 	popl	%eax
    1ed1:	8b 4d 0c 	movl	12(%ebp), %ecx
    1ed4:	8b 55 08 	movl	8(%ebp), %edx
    1ed7:	8d b0 cc 00 00 00 	leal	204(%eax), %esi
    1edd:	c7 45 f4 00 00 00 00 	movl	$0, -12(%ebp)
    1ee4:	89 55 f0 	movl	%edx, -16(%ebp)
    1ee7:	89 4d ec 	movl	%ecx, -20(%ebp)
    1eea:	89 34 24 	movl	%esi, (%esp)
    1eed:	89 85 e8 fe ff ff 	movl	%eax, -280(%ebp)
    1ef3:	e8 7c 00 00 00 	calll	124
    1ef8:	b9 00 01 00 00 	movl	$256, %ecx
    1efd:	8b 95 e8 fe ff ff 	movl	-280(%ebp), %edx
    1f03:	8b b2 38 01 00 00 	movl	312(%edx), %esi
    1f09:	8d bd ec fe ff ff 	leal	-276(%ebp), %edi
    1f0f:	8b 36 	movl	(%esi), %esi
    1f11:	89 3c 24 	movl	%edi, (%esp)
    1f14:	c7 44 24 04 00 01 00 00 	movl	$256, 4(%esp)
    1f1c:	89 74 24 08 	movl	%esi, 8(%esp)
    1f20:	89 85 e4 fe ff ff 	movl	%eax, -284(%ebp)
    1f26:	89 8d e0 fe ff ff 	movl	%ecx, -288(%ebp)
    1f2c:	e8 3d 00 00 00 	calll	61
    1f31:	8d 8d ec fe ff ff 	leal	-276(%ebp), %ecx
    1f37:	89 0c 24 	movl	%ecx, (%esp)
    1f3a:	89 85 dc fe ff ff 	movl	%eax, -292(%ebp)
    1f40:	e8 5b ff ff ff 	calll	-165 <_vulnfunction>
    1f45:	8b 85 e8 fe ff ff 	movl	-280(%ebp), %eax
    1f4b:	8d 88 d4 00 00 00 	leal	212(%eax), %ecx
    1f51:	89 0c 24 	movl	%ecx, (%esp)
    1f54:	e8 1b 00 00 00 	calll	27
    1f59:	31 c9 	xorl	%ecx, %ecx
    1f5b:	89 85 d8 fe ff ff 	movl	%eax, -296(%ebp)
    1f61:	89 c8 	movl	%ecx, %eax
    1f63:	81 c4 30 01 00 00 	addl	$304, %esp
    1f69:	5e 	popl	%esi
    1f6a:	5f 	popl	%edi
    1f6b:	5d 	popl	%ebp
    1f6c:	c3 	retl
Disassembly of section __TEXT,__symbol_stub:
__symbol_stub:
    1f6e:	ff 25 0c 20 00 00 	jmpl	*8204
    1f74:	ff 25 10 20 00 00 	jmpl	*8208
Disassembly of section __TEXT,__stub_helper:
__stub_helper:
    1f7c:	68 04 20 00 00 	pushl	$8196
    1f81:	ff 25 00 20 00 00 	jmpl	*8192
    1f87:	90 	nop
    1f88:	68 00 00 00 00 	pushl	$0
    1f8d:	e9 ea ff ff ff 	jmp	-22 <__stub_helper>
    1f92:	68 0d 00 00 00 	pushl	$13
    1f97:	e9 e0 ff ff ff 	jmp	-32 <__stub_helper>
