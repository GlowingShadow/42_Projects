section .text
	global _ft_strjoin
	extern _ft_strlen
	extern _ft_strnew
	extern _ft_strcat

_ft_strjoin:
	push rbp
	mov rbp, rsp
	push rsi
	push rdi
	call _ft_strlen
	pop rdi
	push rdi
	push rax
	call _ft_strlen
	pop rcx
	add rax, rcx
	mov rdi, rax
	call _ft_strnew
	mov rdi, rax
	pop rsi
	call _ft_strcat
	mov rdi, rax
	pop rsi
	call _ft_strcat
	leave
	ret