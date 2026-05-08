section .text
	global _ft_strcat
	extern _ft_strlen

_ft_strcat:
	push rdi
	push rsi
	call _ft_strlen
	pop rsi
	pop rdi
	add rdi, rax
	push rax
	jmp boucle2

boucle2:
	mov al, [rsi]
	cmp al, 0
	je	end2
	inc rsi
	mov byte[rdi], al
	inc rdi
	pop rax
	inc rax
	push rax
	jmp boucle2

end2:
	pop rax
	sub rdi, rax
	mov rax, rdi
	ret