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

NAME	=	lem-in
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
INCLUDE =	-I includes -I libft/includes

CFILE	=	ft_isdigit_str.c \
			ft_int_strchr.c \
			main.c \
			ft_get_map.c \
			parse_checks.c \
			structure_rooms.c \
			structure_tubes.c \
			structure_ants.c \
			find_room.c \
			commands.c \
			errors.c \
			resolve.c \
			resolve2.c \
			algo_best.c \
			algo_best2.c \
			set_ways.c \
			set_ways_add.c \
			prints.c \
			prints2.c \
			sort_list.c \
			algo_simple.c \
			ft_free_tab.c \
			move.c \
			walk.c

HFILE	=	lemin.h

HDIR	=	includes/
HDR		=	$(patsubst %.h, $(HDIR)%.h, $(HFILE))
SDIR	=	src/
SRC		=	$(patsubst %.c, $(SDIR)%.c, $(CFILE))
ODIR	=	obj/
OBJ		=	$(patsubst %.c, $(ODIR)%.o, $(CFILE))

.PHONY: all compile lib norm clean fclean re

all: compile

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L libft/ -lft 
	@echo "\033[33;32m$(NAME) \033[33;37mcreated"
	@echo "\033[33;35m$(NAME) End\033[33;37m"

$(ODIR)%.o: $(SDIR)%.c $(HDR) Makefile
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

re: fclean all
