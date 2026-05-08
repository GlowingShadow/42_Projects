section .text
	global _ft_tolower

_ft_tolower:
	cmp rdi, 64
	jg 	greater5
	mov rax, rdi
	ret

greater5:
	cmp rdi, 91
	jl 	tolower
	mov rax, rdi
	ret

tolower:
	add rdi, 32
	mov rax, rdi
	ret
