%define	MACH_SYSCALL(nb)	0x2000000 | nb
%define	STDOUT				1
%define	WRITE				4

section .data
hello:
	.string db "hello World!", 10
	.len equ $ - hello.string

section	.text
	global	start
	global	_main
	global	_main2
	extern	_printf

start:
	call _main
	call _main2
	ret

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	lea rdi, [rel hello.string]
	call _printf
	leave
	ret

_main2:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	mov	rdi, 1
	lea rsi, [rel hello.string]
	mov	rdx, hello.len
	mov	rax, MACH_SYSCALL(WRITE)
	syscall
	leave
	ret
