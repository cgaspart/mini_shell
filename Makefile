# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/11 11:11:37 by cgaspart          #+#    #+#              #
#    Updated: 2018/04/30 08:22:16 by cgaspart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC_PATH = src
OBJ_PATH = obj
CPPFLAGS = -Iinclude
LDFLAGS = -L./libft
LDLIBS = -lft
CFLAGS = -Werror -Wall -Wextra
CC = clang
SRC_NAME = main.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(LDFLAGS) -g $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ)
	make -C libft clean
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all, clean, fclean, re
