%define	MACH_SYSCALL(nb)	0x2000000 | nb
%define	STDOUT				1
%define	WRITE				4

section .data
	string db "", 10
	string2 db "(null)", 10

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp
	cmp rdi, 0
	je  null
	push rdi
	call _ft_strlen
	mov	rdx, rax
	pop rsi
	mov	rdi, 1
	mov	rax, MACH_SYSCALL(WRITE)
	syscall
	mov rdi, 1
	mov	rdx, 1
	lea rsi, [rel string]
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	mov rax, 10
	leave
	ret

null:
	mov rdi, 1
	lea rsi, [rel string2]
	mov rdx, 7
	mov	rax, MACH_SYSCALL(WRITE)
	syscall
	mov rax, 10
	leave
	ret