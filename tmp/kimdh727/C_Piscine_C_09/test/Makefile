# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 11:04:22 by donghwki          #+#    #+#              #
#    Updated: 2020/02/06 21:18:13 by donghwki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
# SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c \
# 	   srcs/ft_strcmp.c

SRCS = $(wildcard srcs/*.c)
OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f


CFLAGS = -Wall -Wextra -Werror
INC = -I includes

.SUFFIX : .o .c

%.o:%.c
		${CC} ${CFLAGS} ${INC} -c $< -o ${@}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
