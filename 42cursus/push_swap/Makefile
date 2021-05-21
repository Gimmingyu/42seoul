# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 14:43:22 by kyekim            #+#    #+#              #
#    Updated: 2021/05/17 18:51:22 by kyekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./checker

NAME2 = ./push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC_FILES = main_checker.c		\
			set.c				\
			check.c				\
			move_p.c			\
			move_r.c			\
			move_rr.c			\
			move_s.c			\
			move.c				\
			check_end.c			\
			utils.c

SRC_FILES2 = main_push.c		\
			set.c				\
			move_p.c			\
			move_r.c			\
			move_rr.c			\
			move_s.c			\
			move.c				\
			check.c				\
			check_end.c			\
			pivot_data.c		\
			sort.c				\
			sort_next.c			\
			sort_five.c			\
			utils.c

HEADER_PATH = ./includes/
LIB_PATH = ./libft/
SRC_PATH = ./src/
OBJ_PATH = ./obj/

OBJ_FILES = $(SRC_FILES:.c=.o)
	OBJ_EXEC = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

OBJ_FILES2 = $(SRC_FILES2:.c=.o)
	OBJ_EXEC2 = $(addprefix $(OBJ_PATH), $(OBJ_FILES2))

LIB_FILES = libft.a

LIB = $(addprefix $(LIB_PATH), $(LIB_FILES))

all: $(LIB) $(NAME) $(NAME2) 

$(OBJ_PATH):
	mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(FLAGS) -c $< -o $@ -I $(HEADER_PATH) -I $(LIB_PATH)includes/

$(LIB): .FORCE
	make -C $(LIB_PATH)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJ_EXEC) $(HEADER_PATH)
	$(CC) $(FLAGS) $(OBJ_EXEC) $(LIB) -o $(NAME) -I $(HEADER_PATH) -I $(LIB_PATH)includes/

$(NAME2): $(LIB) $(OBJ_PATH) $(OBJ_EXEC2) $(HEADER_PATH)
	$(CC) $(FLAGS) $(OBJ_EXEC2) $(LIB) -o $(NAME2) -I $(HEADER_PATH) -I $(LIB_PATH)includes/

clean:
	make clean -C libft/
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	make fclean -C libft/
	/bin/rm -rf $(NAME) $(NAME2)

re: fclean all

.FORCE:
.PHONY: all, clean, fclean, re
