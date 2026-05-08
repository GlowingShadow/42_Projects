# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/15 17:38:19 by REDACTED          #+#    #+#              #
#    Updated: 2015/06/04 09:53:09 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_minishell1
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3
INCLUDE =	-I includes -I libft/includes

CFILE	=	main.c \
			env.c \
			ft_cd.c \
			ft_find_var.c \
			tools.c \
			error_and_checks.c \
			ft_tabdup.c

HFILE	=	sh1.h

HDIR	=	includes/
HDR		=	$(patsubst %.h, $(HDIR)%.h, $(HFILE))
SDIR	=	src/
SRC		=	$(patsubst %.c, $(SDIR)%.c, $(CFILE))
ODIR	=	obj/
OBJ		=	$(patsubst %.c, $(ODIR)%.o, $(CFILE))

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@make -C libft/
	@$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)
	@echo "\033[33;32m$(NAME) \033[33;37mcreated"
	@echo "\033[33;35m$(NAME) End\033[33;37m"

$(ODIR)%.o: $(SDIR)%.c $(HDR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[33;33m\t$@ compiled\033[33;37m"

norm:
	norminette $(SDIR) $(HDR)

clean: 
	@rm -f $(OBJ)
	@echo "\033[33;33mAll objects \033[33;31mdeleted\033[33;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;32m$(NAME) \033[33;31mdeleted\033[33;37m"

re: fclean all
