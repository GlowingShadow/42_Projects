section .text
	global	_ft_isascii

_ft_isascii:
	cmp	rdi, 0
	jge	greater4
	mov	rax, 0
	ret

greater4:
	cmp	rdi, 128 
	jl ascii
	mov	rax, 0
	ret 

ascii:
	mov	rax, 1
	ret
