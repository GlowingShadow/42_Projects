section .text
	global _ft_memset

_ft_memset:
	mov rax, rsi
	mov rcx, rdx
	rep stosb
	sub rdi, rdx
	mov rax, rdi
	ret