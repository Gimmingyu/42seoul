CC = gcc
CFLAGS = -Wall -Wextra -Werror
OPTION = -I $(HEADER)

NAME = rush-02

HEADER = ./includes/
SRC_DIR = ./srcs/

SRCS = ft_main.c \
	   dict_parser.c \
	   dict.c \
	   dict_list.c \
	   hash.c \
	   ft_string.c \
	   ft_string2.c \
	   read_file.c \
	   file_to_hash.c \
	   input_validation.c \
	   find.c \
	   find_util.c \
	   print_entry.c
OBJS = $(addprefix $(SRC_DIR), $(SRCS:.c=.o))


.c.o :
	$(CC) $(CFLAGS) $(OPTION) -c -o $@ $<

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : clean all
