# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/15 17:38:19 by REDACTED          #+#    #+#              #
#    Updated: 2018/01/20 19:18:57 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Grace
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

SRC				=	Grace.c

OBJ_DIR			=	obj
OBJ				=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))

.PHONY: all compile clean fclean re

all: compile

compile:
	@mkdir -p $(OBJ_DIR)
	@$(MAKE) $(NAME)

$(NAME): $(SRC) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -f Grace_kid.c

fclean: clean
	rm -f $(NAME)

re: fclean all
