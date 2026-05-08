section .text
	global	_ft_isalpha

_ft_isalpha:
	cmp	rdi, 64
	jg	greater2
	mov	rax, 0
	ret

greater2:
	cmp	rdi, 123
	jl lower
	mov	rax, 0
	ret 

lower:
	cmp	rdi, 91
	jl	alpha
	cmp	rdi, 96
	jg	alpha
	mov	rax, 0
	ret

alpha:
	mov	rax, 1
	ret
