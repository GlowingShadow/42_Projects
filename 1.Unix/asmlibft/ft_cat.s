%define	MACH_SYSCALL(nb)	0x2000000 | nb
%define READ				3
%define	WRITE				4

section .bss
	buf: resb 5

section .text
	global _ft_cat
	extern _ft_puts

_ft_cat:
	push rdi
	mov rdx, 5
	lea rsi, [rel buf]
	mov	rax, MACH_SYSCALL(READ)
	syscall
	jc	end3
	cmp rax, 0
	jle end3
	mov rdi, 1
	mov rdx, rax
	lea rsi, [rel buf]
	mov rax, MACH_SYSCALL(WRITE)
	syscall
	pop rdi
	cmp rax, 0
	jnz _ft_cat

end3:
	pop rdi
	ret