AR = ar
ARFLAGS = crv
CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = libft.a

INCLUDES_DIR = ./includes
INCLUDES = ft.h

SRCS_DIR = ./srcs
SRCS = ft_putchar.c \
	   ft_swap.c \
	   ft_putstr.c \
	   ft_strlen.c \
	   ft_strcmp.c
OBJS = $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

all : $(TARGET)

clean : 
	rm -f $(OBJS)

fclean : 
	rm -f $(TARGET)

re : fclean all

$(TARGET) : $(addprefix $(INCLUDES_DIR)/, $(INCLUDES)) $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.c.o : 
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $(<:.c=.o)
