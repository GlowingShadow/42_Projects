# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 20:07:50 by REDACTED          #+#    #+#              #
#    Updated: 2015/05/15 15:37:56 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	libfts.a
CFLAGS	=	-Wall -Wextra -Werror
CC		=	gcc

SRC		=	./ft_bzero.s \
			./ft_cat.s \
			./ft_isalnum.s \
			./ft_isalpha.s \
			./ft_isascii.s \
			./ft_isdigit.s \
			./ft_isprint.s \
			./ft_memcpy.s \
			./ft_memset.s \
			./ft_puts.s \
			./ft_strcat.s \
			./ft_strchr.s \
			./ft_strdup.s \
			./ft_strequ.s \
			./ft_strjoin.s \
			./ft_strlen.s \
			./ft_strnew.s \
			./ft_strrchr.s \
			./ft_tolower.s \
			./ft_toupper.s


OBJ		=	$(SRC:.s=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@make -C libft/ fclean
	@make -C libft/
	@echo Libft.a created
	
	@ar rc $(NAME) $(OBJ)
	@echo ASM created
	@echo ""	
	@echo End

%.o: %.s
	@~/.brew/bin/nasm -f macho64 $<
	@echo "\033[33;33m\t$@ compiled\033[33;37m"

clean:
	@rm -f $(OBJ)
	@echo "\033[33;33mAll objects \033[33;31mdeleted\033[33;37m"	

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;32m$(NAME) \033[33;31mdeleted\033[33;37m"

re: fclean all
