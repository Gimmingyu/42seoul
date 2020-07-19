CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = do-op

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) ft_atoi.c main.c ops.c -o $(NAME) -I

clean :
	$(RM) *.o
	
fclean : clean
	$(RM) $(NAME)
