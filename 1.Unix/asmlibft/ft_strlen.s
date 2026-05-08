global _ft_strlen

section .text

_ft_strlen:
	push rbp
	mov rbp, rsp
	mov	rax, 0
	mov	rcx, -1
	cld
	repne scasb
	mov	rax, -2
	sub rax, rcx
	leave
	ret