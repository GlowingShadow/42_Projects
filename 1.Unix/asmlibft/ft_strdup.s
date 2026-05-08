section .text
	global _ft_strdup
	extern _ft_strlen
	extern _malloc
	extern _ft_memcpy

_ft_strdup:
	push rbp
	mov rbp, rsp
	push rdi
	call _ft_strlen
	mov rdi, rax
	push rax
	call _malloc
	mov rdi, rax
	pop rdx
	pop rsi
	call _ft_memcpy
	leave
	ret