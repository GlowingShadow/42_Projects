# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 20:07:50 by REDACTED          #+#    #+#              #
#    Updated: 2015/04/04 07:07:03 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	computor
CFLAGS	=	-Wall -Wextra -Werror
GCC		=	gcc

SRC		=	./main.c \
			./ft_cut.c \
			./ft_parsing_checks.c \
			./ft_stock_value.c \
			./ft_display.c \
			./ft_solve.c \
			./ft_fabs.c \
			./ft_sqrt.c

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/ fclean
	@make -C libft/
	@echo Libft.a created
	@$(GCC) $(CFLAGS) -O3 -I includes/ -I libft/includes/ -c $(SRC)
	@$(GCC) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo Compilation complete
	@echo End

clean:
	@rm -f $(OBJ)
	@echo All objects deleted	

fclean: clean
	@rm -f $(NAME)
	@echo $(NAME) deleted

re: fclean all
