~/.brew/bin/nasm -f macho64 ft_isalnum.s
~/.brew/bin/nasm -f macho64 ft_isdigit.s
~/.brew/bin/nasm -f macho64 ft_isalpha.s
~/.brew/bin/nasm -f macho64 ft_isprint.s
~/.brew/bin/nasm -f macho64 ft_isascii.s
~/.brew/bin/nasm -f macho64 ft_tolower.s
~/.brew/bin/nasm -f macho64 ft_toupper.s
~/.brew/bin/nasm -f macho64 ft_strlen.s
~/.brew/bin/nasm -f macho64 ft_puts.s
~/.brew/bin/nasm -f macho64 ft_bzero.s
~/.brew/bin/nasm -f macho64 ft_strcat.s
~/.brew/bin/nasm -f macho64 ft_memset.s
~/.brew/bin/nasm -f macho64 ft_memcpy.s
~/.brew/bin/nasm -f macho64 ft_strdup.s
~/.brew/bin/nasm -f macho64 ft_cat.s
~/.brew/bin/nasm -f macho64 ft_strchr.s
~/.brew/bin/nasm -f macho64 ft_strrchr.s
~/.brew/bin/nasm -f macho64 ft_strnew.s
~/.brew/bin/nasm -f macho64 ft_strjoin.s
gcc -Wall -Wextra -Werror -O3 -I includes/ -I libft/includes/ -c main.c
gcc ft_isalnum.o ft_isalpha.o ft_isdigit.o ft_isprint.o ft_isascii.o ft_tolower.o ft_toupper.o ft_strlen.o ft_puts.o ft_bzero.o ft_strcat.o ft_memset.o ft_memcpy.o ft_strdup.o ft_cat.o ft_strchr.o ft_strrchr.o ft_strnew.o ft_strjoin.o main.o -L libft/ -lft
