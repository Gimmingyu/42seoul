CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET = ft_cat
SRCS = ft_cat.c
OBJS = $(SRCS:.c=.o)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(TARGET)

clean :
	rm -f $(OBJS)

fclean :
	$(MAKE) clean
	rm -f $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
