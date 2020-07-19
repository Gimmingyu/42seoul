# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/01 14:48:05 by donghwki          #+#    #+#              #
#    Updated: 2020/02/02 19:56:09 by donghwki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush_01.o
SRCS = srcs/main.c srcs/rush_01.c srcs/rush_01_mem.c srcs/rush_01_check.c

OBJS = ${SRCS:.c=.o}

CC		= gcc
CFLAGS = -Wall -Wextra -Werror

RM		= rm -f

INC = -I includes

.SUFFIX : .c .o

.c.o:
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${INC} ${SRCS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
