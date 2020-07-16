CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET = ft_tail
SRCS = ft_tail.c ft_check_input.c
OBJS = $(SRCS:.c=.o)
INCS = header.h

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(TARGET)

clean :
	rm -f $(OBJS)

fclean :
	$(MAKE) clean
	rm -f $(TARGET)

%.o : %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
