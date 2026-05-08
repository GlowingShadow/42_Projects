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

NAME	=	lemipc
CC		=	gcc
CFLAGS	=	-Wall -Wextra
INCLUDE =	-I includes -I libft/includes

CFILE	=	main.c \
			init_msgq.c \
			init_ipcs.c \
			delete_ipcs.c \
			game_over.c \
			misc.c \
			check_dead.c \
			move.c \
			chase.c \
			leader.c \
			search.c

HFILE	=	lemipc.h

HDIR	=	includes/
HDR		=	$(patsubst %.h, $(HDIR)%.h, $(HFILE))
SDIR	=	src/
SRC		=	$(patsubst %.c, $(SDIR)%.c, $(CFILE))
ODIR	=	obj/
OBJ		=	$(patsubst %.c, $(ODIR)%.o, $(CFILE))

.PHONY: all compile lib aff norm clean fclean re

all: compile

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft
	@echo "\033[33;32m$(NAME) \033[33;37mcreated"
	@echo "\033[33;35m$(NAME) End\033[33;37m"

$(ODIR)%.o: $(SDIR)%.c $(HDR) Makefile
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[33;33m\t$@ compiled\033[33;37m"

compile: lib aff
	@mkdir -p obj/
	@$(MAKE) $(NAME)

lib:
	@$(MAKE) -C libft/

aff:
	@$(MAKE) -C lemipc_affichage

norm:
	norminette $(SRC) $(HDR)

clean:
	@rm -f $(OBJ)
	@echo "\033[33;33mAll objects \033[33;31mdeleted\033[33;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;32m$(NAME) \033[33;31mdeleted\033[33;37m"

re: fclean all
