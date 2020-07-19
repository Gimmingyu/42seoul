CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libft.a

SRC = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@ -I includes/

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all
