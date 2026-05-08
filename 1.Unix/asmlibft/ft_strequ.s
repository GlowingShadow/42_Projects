section .text
	global _ft_strequ
	extern _ft_strlen

_ft_strequ:
	push rbp
	mov rbp, rsp
	push rdi
	push rsi
	call _ft_strlen
	mov rcx, rax
	pop rsi
	pop rdi
	cld
	repe cmpsb
	cmp byte[rdi], 0
	je part2
	jmp notequal

part2:
	cmp byte[rsi], 0
	je equal
	jmp notequal

equal:
	mov rax, 1
	leave
	ret

notequal:
	mov rax, 0
	leave
	ret