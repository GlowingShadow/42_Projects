section .text
	global _ft_strrchr
	extern _ft_strlen

_ft_strrchr:
	push rbp
	mov rbp, rsp

search2:
	push rdi
	push rsi
	call _ft_strlen
	mov rcx, rax
	pop rax
	pop rdi
	add rdi, rcx
	inc rcx
	cmp rax, 0
	je	zero2
	std
	repne scasb
	je	found2
	jmp notfound2
	
zero2:
	mov rax, rdi
	leave
	ret

found2:
	inc rdi
	mov rax, rdi
	leave
	ret

notfound2:
	mov rax, 0
	leave
	ret