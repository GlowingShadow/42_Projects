# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 20:07:50 by REDACTED          #+#    #+#              #
#    Updated: 2015/01/23 02:34:10 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	fdf
CFLAGS	=	-Wall -Wextra -Werror
GCC		=	gcc

SRC		=	./main.c \
			./get_next_line.c \
			./ft_clear_tab.c \
			./ft_get_coo.c \
			./ft_itaballoc.c \
			./ft_putnbr_str.c \
			./ft_putnbr_tab.c \
			./ft_tablen.c \
			./ft_tablen_int.c \
			./ft_puttab.c \
			./ft_valid_line.c \
			./ft_valid_tab.c \
			./ft_assign_xy.c \
			./ft_print_win.c \
			./ft_case.c \
			./ft_color.c \
			./ft_altitude.c \
			./ft_diff_altitude.c \
			./ft_mlx_image_put_pixel.c \
			./ft_launch_mlx.c \
			./ft_keys.c

all: $(NAME)

$(NAME): $(SRC)
	@$(GCC) $(CFLAGS) $(SRC) -o $(NAME) libft.a -L/usr/X11/lib -lmlx -lXext -lX11
	@echo Fin

clean: 

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) deleted

re: fclean all
