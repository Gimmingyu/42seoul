
CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = bsq

all : $(NAME)

$(NAME) :
		$(CC) $(CFLAGS) *.c -o $(NAME) -I

clean :
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)

re : fclean all
