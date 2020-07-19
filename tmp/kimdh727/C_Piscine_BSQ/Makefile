# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 00:07:39 by donghwki          #+#    #+#              #
#    Updated: 2020/02/11 23:44:18 by donghwki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSQ
SRCS = ${wildcard srcs/*.c}

OBJS = ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

INC = -I includes

.SUFFIX : .c .o

.c.o:
		${CC} ${CFLAGS} ${INC} -c ${<} -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${INC} ${SRCS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
