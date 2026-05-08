section .text
	global _ft_toupper

_ft_toupper:
	cmp rdi, 96
	jg 	greater6
	mov rax, rdi
	ret

greater6:
	cmp rdi, 123
	jl 	toupper
	mov rax, rdi
	ret

toupper:
	sub rdi, 32
	mov rax, rdi
	ret
