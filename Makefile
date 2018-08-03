# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swilson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/20 09:23:02 by swilson           #+#    #+#              #
#    Updated: 2018/08/03 11:33:20 by swilson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./src/
OBJ_PATH = ./obj/
HDR_PATH = ./include/
INC_PATH = $(HDR_PATH) ./libft/
LIB_PATH = ./libft/
LIB_NAME = ./libft/libft.a

NAME = pusher
HEADER = include/push_swap.h
SRC_NAME = push_swap.c checkall.c setall.c sorting.c get_next_line.c\
		   isit.c
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) 
	@make -C ./libft/
	$(CC) $(LIB) $(LIB_NAME) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INCLUDE)
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

norm:
	norminette $(wordlist 1, 10, $(SRC))
	norminette $(wordlist 1, 2, $(HDR_PATH))
	make -C ./libft/ norm

clean:
	@make -C ./libft/ fclean
	@rm -rf $(OBJ) $(OBJ_PATH) filler.trace

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: norm clean fclean re
