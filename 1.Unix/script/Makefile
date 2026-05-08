# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/15 17:38:19 by REDACTED          #+#    #+#              #
#    Updated: 2016/02/15 06:35:34 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_script
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3
INCLUDE =	-I includes -I libft/includes

CFILE	=	main.c \
			forker.c \
			ft_synth.c \
			ft_print_time.c \
			ft_isdigit_str.c \
			misc.c

HFILE	=	script.h

HDIR	=	includes/
HDR		=	$(patsubst %.h, $(HDIR)%.h, $(HFILE))
SDIR	=	src/
SRC		=	$(patsubst %.c, $(SDIR)%.c, $(CFILE))
ODIR	=	obj/
OBJ		=	$(patsubst %.c, $(ODIR)%.o, $(CFILE))

all: compile

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)
	@echo "\033[33;32m$(NAME) \033[33;37mcreated"
	@echo "\033[33;35m$(NAME) End\033[33;37m"

$(ODIR)%.o: $(SDIR)%.c $(HDR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[33;33m\t$@ compiled\033[33;37m"

compile:
	@mkdir -p obj/
	@$(MAKE) -C libft
	@$(MAKE) $(NAME)

lib:
	@$(MAKE) -C libft/

norm:
	norminette $(SRC) $(HDR)

clean: 
	@rm -f $(OBJ)
	@echo "\033[33;33mAll objects \033[33;31mdeleted\033[33;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;32m$(NAME) \033[33;31mdeleted\033[33;37m"

re: fclean compile
