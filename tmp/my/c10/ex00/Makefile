CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_main.c
OBJS = $(SRCS:.c=.o)

TARGET = ft_display_file

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

all : $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : all clean fclean re
