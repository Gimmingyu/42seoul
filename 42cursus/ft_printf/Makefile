# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 19:38:27 by kyekim            #+#    #+#              #
#    Updated: 2021/02/27 11:39:00 by kyekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


PATH_SRCS =		./srcs/

PATH_LIB =		./libft/

SRCS =			${PATH_SRCS}ft_allflag_check.c		\
				${PATH_SRCS}ft_display_37.c			\
				${PATH_SRCS}ft_display_88xpo.c			\
				${PATH_SRCS}ft_display_all.c		\
				${PATH_SRCS}ft_display_c.c			\
				${PATH_SRCS}ft_display_diu.c			\
				${PATH_SRCS}ft_display_e.c			\
				${PATH_SRCS}ft_display_f.c			\
				${PATH_SRCS}ft_display_g.c			\
				${PATH_SRCS}ft_display_s.c			\
				${PATH_SRCS}ft_dtof.c				\
				${PATH_SRCS}ft_frac_util.c			\
				${PATH_SRCS}ft_handle_n.c			\
				${PATH_SRCS}ft_isspecial.c			\
				${PATH_SRCS}ft_printf.c				\
				${PATH_SRCS}ft_putnbr_mk2.c			\
				${PATH_SRCS}ft_putnbr_mkf.c			\
				${PATH_SRCS}ft_read_para.c			\
				${PATH_SRCS}ft_sub_printf.c

OBJS =			${SRCS:.c=.o}

INCS =			./include/

LIB_NAME =		libft.a

NAME =			libftprintf.a

AR =			ar rc

CC =			gcc

RM =			rm -f

CFLAGS =		-Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}
	
${NAME} : lib ${OBJS}
	cp ${PATH_LIB}${LIB_NAME} ./
	mv ${LIB_NAME} ${NAME}
	${AR} ${NAME} ${OBJS}

bonus : ${NAME}

lib :
	make -C ${PATH_LIB}

all : ${NAME}

clean :
	${RM} ${OBJS}
	make fclean -C ${PATH_LIB}

fclean : clean
	${RM} ${NAME}

re : fclean all
