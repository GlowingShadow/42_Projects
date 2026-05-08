section .text
	global	_ft_isprint

_ft_isprint:
	cmp	rdi, 31
	jg	greater3
	mov	rax, 0
	ret

greater3:
	cmp	rdi, 127
	jl print
	mov	rax, 0
	ret 

print:
	mov	rax, 1
	ret
