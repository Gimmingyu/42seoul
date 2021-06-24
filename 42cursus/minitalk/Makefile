# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 16:03:23 by kyekim            #+#    #+#              #
#    Updated: 2021/06/24 14:32:45 by kyekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = ./server
NAME2 = ./client
all: server client
server:
	$(CC) $(FLAGS) server.c -o $(NAME)
client:
	$(CC) $(FLAGS) client.c -o $(NAME2)
clean:
	rm $(NAME) $(NAME2)
fclean: clean
re: fclean all


NAME3 = ./server_bonus
NAME4 = ./client_bonus
bonus: b_server b_client
b_server:
	$(CC) $(FLAGS) server_bonus.c -o $(NAME3)
b_client:
	$(CC) $(FLAGS) client_bonus.c -o $(NAME4)
b_clean:
	rm $(NAME3) $(NAME4)
b_fclean: b_clean
b_re: b_fclean bonus

.FORCE:
.PHONY: all, clean, fclean, re, bonus, b_clean, b_fclean, b_re
