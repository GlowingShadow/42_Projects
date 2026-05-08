section .text
	global	_ft_isdigit

_ft_isdigit:
	cmp	rdi, 47
	jg	greater
	mov	rax, 0
	ret

greater:
	cmp	rdi, 58
	jl digit
	mov	rax, 0
	ret 

digit:
	mov	rax, 1
	ret
