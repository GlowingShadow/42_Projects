# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/01 22:40:03 by REDACTED          #+#    #+#              #
#    Updated: 2015/05/03 22:56:16 by jpucelle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror -O3
CC		=	gcc

NAME	=	arkanoid
GLFWLIB	=	libglfw3.a
LIBFT	=	libft.a

SRC		=	main.c \
			ark_display.c \
			ark_draw.c \
			ark_print.c \
			ark_drawinfo.c \
			ark_drawbubble.c \
			ark_parse.c \
			ark_color.c \
			ark_launchbubble.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@git submodule init
	@git submodule update
	@cd glfw_src && cmake -DCMAKE_INSTALL_PREFIX=../glfw .
	@make install -sC glfw_src
	@echo "\033[33;36m$(GLFWLIB)\033[33;37m created"
	@make -sC libft/
	@echo $(LIBFT) created
	@$(CC) -L glfw/lib -L libft/ -lft -o $(NAME) $(OBJ) -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -framework AppKit 
	@echo "\033[33;32m$(NAME) compiled\033[33;37m"
	@echo "\033[33;35mEnd\033[33;37m"

%.o: %.c
	@$(CC) $(CFLAGS) -O3 -I includes -I libft/includes -I glfw/include -c $< -o $@
	@echo "\033[33;33m\t$@ compiled\033[33;37m"

clean:
	@rm -f $(OBJ)
	@echo "\033[33;33mAll objects \033[33;31mdeleted\033[33;37m"	

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;32m$(NAME) \033[33;31mdeleted\033[33;37m"

re: fclean all
