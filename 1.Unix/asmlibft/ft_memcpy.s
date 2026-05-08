section .text
	global _ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp
	mov rax, rsi
	mov rcx, rdx
	rep movsb
	sub rdi, rdx
	mov rax, rdi
	leave
	ret
