# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 15:35:27 by kyekim            #+#    #+#              #
#    Updated: 2020/10/01 01:20:35 by kyekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRCS = ./Libft/

SRC = ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c \
	  ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
	  ft_strncmp.c ft_atoi.c ft_bzero.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c \
	  ft_calloc.c ft_strdup.c \
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c ft_strmapi.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_B = ft_lstnew.c ft_lstadd_front.c ft_lstlast.c \
		ft_lstsize.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c -I $(SRCS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

bonus:
	$(CC) $(CFLAGS) -c -I $(SRCS) $(SRC_B)
	ar rc $(NAME) $(OBJ_B)

re: fclean all

.PHONY: bonus all clean fclean re
