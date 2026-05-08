# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/15 17:38:19 by REDACTED          #+#    #+#              #
#    Updated: 2015/10/13 19:49:18 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

CFILE	=	main.c \
			get_map.c \
			adjust_map.c\
			solve.c

HFILE	=	fillit.h

HDIR	=	./
HDR		=	$(patsubst %.h, $(HDIR)%.h, $(HFILE))
SDIR	=	./
SRC		=	$(patsubst %.c, $(SDIR)%.c, $(CFILE))
ODIR	=	./
OBJ		=	$(patsubst %.c, $(ODIR)%.o, $(CFILE))

.PHONY: all compile lib norm clean fclean re

all: compile

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) libft/libft.a
	@echo "\033[33;32m$(NAME) \033[33;37mcreated"
	@echo "\033[33;35m$(NAME) End\033[33;37m"

$(ODIR)%.o: $(SDIR)%.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[33;33m\t$@ compiled\033[33;37m"

compile:
	@mkdir -p obj/
	@$(MAKE) -C libft
	@$(MAKE) $(NAME)

lib:
	@$(MAKE) -C libft/

norm:
	norminette $(SDIR) $(HDR)

clean: 
	@rm -f $(OBJ)
	@echo "\033[33;33mAll objects \033[33;31mdeleted\033[33;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;32m$(NAME) \033[33;31mdeleted\033[33;37m"

re: fclean all
