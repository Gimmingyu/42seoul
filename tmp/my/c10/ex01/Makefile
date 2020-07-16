CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_main.c
OBJS = $(SRCS:.c=.o)

NAME = ft_cat

$(NAME) : $(OBJS)
	$(CC) $(CLFAGS) -o $@ $^

all : $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
