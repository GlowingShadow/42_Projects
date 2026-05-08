section .text
	global _ft_strchr
	extern _ft_strlen

_ft_strchr:
	push rbp
	mov rbp, rsp

search:
	push rdi
	push rsi
	call _ft_strlen
	mov rcx,rax
	pop rax
	pop rdi
	cmp rax, 0
	je	zero
	cld
	repne scasb
	je	found
	jmp notfound
	
zero:
	add rdi, rcx
	mov rax, rdi
	leave
	ret

found:
	dec rdi
	mov rax, rdi
	leave
	ret

notfound:
	mov rax, 0
	leave
	ret