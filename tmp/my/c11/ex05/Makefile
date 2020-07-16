CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c \
	   operators.c \
	   ft_atoi.c \
	   ft_putnbr.c
OBJS = $(SRCS:.c=.o)

TARGET = do-op

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(TARGET)

.c.o :
	$(CC) $(CFLAGS) -c -o $(<:.c=.o) $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -r $(TARGET)

re : fclean all
