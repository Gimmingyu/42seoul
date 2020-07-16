# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/14 18:28:05 by sungpark          #+#    #+#              #
#    Updated: 2020/07/15 17:29:34 by sungpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET	= libft.a

AR = ar
ARFLAGS = crv
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

INC_DIR	= ./includes
INC		= ft.h
SRC_DIR = ./srcs
SRCS	= ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c ft_swap.c

OBJS = ${addprefix ${SRC_DIR}/, ${SRCS:.c=.o}}

all: ${TARGET}

${TARGET} : ${addprefix ${INC_DIR}/, ${INC}} ${OBJS}
	${AR} ${ARFLAGS} $@ $^

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INC_DIR}

clean:
	/bin/rm -f ${OBJS}

fclean: clean
	/bin/rm -f ${TARGET}

re: fclean all
