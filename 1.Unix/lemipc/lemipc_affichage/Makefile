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

NAME	=	aff_lemipc
CC		=	gcc
CFLAGS	=	-Wall -Wextra
INCLUDE =	-I includes -I ../libft/includes -I SDL2-2.0.4/include
LIBS	=	SDL2-2.0.4/build/.libs/libSDL2-2.0.0.dylib \
			SDL2-2.0.4/build/.libs/libSDL2.dylib \
			SDL2-2.0.4/build/.libs/libSDL2.a
MLX		=	-lmlx -framework OpenGL -framework AppKit

CFILE	=	main.c \
			init_ipcs.c \
			launch_mlx.c \
			ft_mlx_image_put_pixel.c \
			images.c \
			draw.c \
			register.c \
			misc.c

HFILE	=	lemipc_aff.h

HDIR	=	includes/
HDR		=	$(patsubst %.h, $(HDIR)%.h, $(HFILE))
SDIR	=	src/
SRC		=	$(patsubst %.c, $(SDIR)%.c, $(CFILE))
ODIR	=	obj/
OBJ		=	$(patsubst %.c, $(ODIR)%.o, $(CFILE))

.PHONY: all compile norm clean fclean re

all: compile

$(NAME): $(SRC) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L ../libft/ -lft $(MLX)
	@echo "\033[33;32m$(NAME) \033[33;37mcreated"
	@echo "\033[33;35m$(NAME) End\033[33;37m"

$(ODIR)%.o: $(SDIR)%.c $(HDR) Makefile
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "\033[33;33m\t$@ compiled\033[33;37m"

compile:
	@mkdir -p obj/
	@$(MAKE) $(NAME)
	@cp $(NAME) ../

norm:
	norminette $(SRC) $(HDR)

clean:
	@rm -f $(OBJ)
	@echo "\033[33;33mAll objects \033[33;31mdeleted\033[33;37m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[33;32m$(NAME) \033[33;31mdeleted\033[33;37m"

re: fclean all
