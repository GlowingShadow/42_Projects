# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: REDACTED <REDACTED@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/15 17:38:19 by REDACTED          #+#    #+#              #
#    Updated: 2017/07/03 16:41:53 by REDACTED         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	Grace
CC				=	clang++
CFLAGS			=	-Wall -Wextra -Wextra

SRC				=	Grace.cpp

OBJ_DIR			=	obj
OBJ				=	$(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

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
	rm -rf Grace_kid.cpp

fclean: clean
	rm -f $(NAME)

re: fclean all
