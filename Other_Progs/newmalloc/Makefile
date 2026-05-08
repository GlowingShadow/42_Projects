# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/01 05:14:23 by REDACTED          #+#    #+#              #
#    Updated: 2015/03/30 13:36:33 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif
FLAG = -Wall -Wextra -I ./libft/includes/ #-Werror 
NAME = libft_malloc_$(HOSTTYPE).so 
SRC = malloc.c
SRCO = $(SRC:.c=.o)
#LIBS = -L./libft -lft

all : $(NAME)
$(NAME) :
#	make -C ./libft
	gcc -shared -fPIC $(FLAG) -o $(NAME)  $(SRC) 
clean :
	rm -f $(SRCO)
fclean : clean
	rm -f $(NAME)
re : fclean all
