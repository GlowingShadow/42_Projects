# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 20:07:50 by REDACTED          #+#    #+#              #
#    Updated: 2015/02/19 12:26:10 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	ft_ls
CFLAGS	=	-g -Wall -Wextra -Werror
GCC		=	gcc

SRC		=	./main.c \
			./ft_bad_argument.c \
			./ft_bigputnbr.c \
			./ft_clean.c \
			./ft_clear.c \
			./ft_device_len.c \
			./ft_file_argv.c \
			./ft_get_time.c \
			./ft_grep.c \
			./ft_ls.c \
			./ft_lsa.c \
			./ft_make_arg.c \
			./ft_maketab_dir.c \
			./ft_maketab_ls.c \
			./ft_maketab_lsl.c \
			./ft_maketab_lsr.c \
			./ft_maketab_lst.c \
			./ft_nputchar.c \
			./ft_option.c \
			./ft_perm.c \
			./ft_print.c \
			./ft_put2str.c \
			./ft_puttab.c \
			./ft_puttab_stats.c \
			./ft_puttab_stats_dev.c \
			./ft_stats_len.c \
			./ft_stats_len_target.c \
			./ft_strjoin_free.c \
			./ft_strswap.c \
			./ft_synth.c \
			./ft_tabjoin.c \
			./ft_tablen.c \
			./ft_tabsort.c

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft/ fclean
	@make -C libft/
	@echo Libft.a created
	@$(GCC) $(CFLAGS) -I includes/ -I libft/includes/ -c $(SRC)
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
