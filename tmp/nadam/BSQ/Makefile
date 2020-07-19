CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCS = -I ./includes/

SRC_DIR = ./srcs/
SRCS = ft_main.c \
	   ft_string.c \
	   file_reader.c \
	   map_reader.c \
	   map_validation.c \
	   largest_square_finder.c \
	   answer_printer.c \
	   stdin_reader.c \
	   ft_split.c \
	   ft_atoi.c
OBJS = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))

NAME = bsq

.c.o :
	$(CC) $(CFLAGS) -c -o $@ $< $(INCS)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
