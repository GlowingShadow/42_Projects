# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 20:07:50 by REDACTED          #+#    #+#              #
#    Updated: 2015/03/17 21:44:46 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	push_swap
CFLAGS	=	-g -Wall -Wextra -Werror
GCC		=	gcc

SRC		=	./main.c \
			./ft_operation.c \
			./ft_operation2.c \
			./ft_op1.c \
			./ft_op2.c \
			./ft_op3.c \
			./ft_read_op.c \
			./ft_valid_argv.c \
			./ft_clear_zero.c \
			./ft_synth.c \
			./ft_sort_int_tab.c \
			./ft_putnbr_str.c \
			./ft_atoi_tab.c \
			./ft_find_smaller_int.c \
			./ft_algo1.c \
			./ft_algo2.c \
			./ft_algo3.c \
			./ft_check_integer.c \
			./ft_intswap.c \
			./ft_int_tab_dup.c \
			./ft_strjoin_free.c \
			./ft_check_mvt.c \
			./ft_option.c

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/ fclean
	@make -C libft/
	@echo Libft.a created
	@$(GCC) $(CFLAGS) -O3 -I includes/ -I libft/includes/ -c $(SRC)
	@$(GCC) -o $(NAME) $(OBJ) -L libft/ -lft -lmlx -framework OpenGL -framework AppKit
	@echo Compilation complete
	@echo End

clean:
	@rm -f $(OBJ)
	@echo All objects deleted	

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) deleted

re: fclean all
