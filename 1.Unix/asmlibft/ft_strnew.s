section .text
	global _ft_strnew
	extern _malloc
	extern _ft_bzero

_ft_strnew:
	push rbp
	mov rbp, rsp
	push rdi
	call _malloc
	pop rsi
	mov rdi, rax
	call _ft_bzero
	leave
	ret
