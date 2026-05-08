section .text
	global	_ft_isalnum
	extern	_ft_isalpha
	extern	_ft_isdigit
		
_ft_isalnum:
	call _ft_isalpha
	cmp rax, 0
	jz	digit2
	mov rax, 1
	ret

digit2:
	call _ft_isdigit
	cmp rax, 0
	jz	alnum
	mov	rax, 1
	ret

alnum:
	mov rax, 0
	ret
