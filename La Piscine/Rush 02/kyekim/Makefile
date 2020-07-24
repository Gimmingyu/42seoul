CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = rush-02

all: $(NAME)

$(NAME) : 
		$(CC) $(CFLAGS) *.c -o $(NAME)

clean :
		rm -rf *.o

fclean : clean
		rm -rf $(NAME)

re:	fclean all