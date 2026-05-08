section .text
	global _ft_bzero

_ft_bzero:
	cmp rsi, 0
	je	end

boucle:
	cmp rsi, 0
	jle  end
	mov byte[rdi], 0
	inc rdi
	dec rsi
	jmp _ft_bzero

end:
	ret