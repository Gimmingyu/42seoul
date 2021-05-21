# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 04:53:30 by kyekim            #+#    #+#              #
#    Updated: 2021/05/17 18:50:59 by kyekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = 	ft_memset.c				\
		ft_bzero.c				\
		ft_memcpy.c				\
		ft_memccpy.c			\
		ft_memmove.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_strcpy.c 			\
		ft_strdup.c 			\
		ft_strlen.c 			\
		ft_strncpy.c			\
		ft_strcat.c				\
		ft_strlcat.c			\
		ft_strncat.c			\
		ft_strcmp.c				\
		ft_strncmp.c			\
		ft_atoi.c				\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strstr.c				\
		ft_strnstr.c			\
		ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_memalloc.c			\
		ft_memdel.c				\
		ft_strnew.c				\
		ft_strdel.c				\
		ft_strdel_d.c			\
		ft_strclr.c				\
		ft_striter.c			\
		ft_striteri.c			\
		ft_strmap.c				\
		ft_strmapi.c			\
		ft_strequ.c				\
		ft_strnequ.c			\
		ft_strsub.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_strsplit.c			\
		ft_itoa.c				\
		ft_putchar.c			\
		ft_putstr.c				\
		ft_putendl.c			\
		ft_putnbr.c				\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_lstnew.c				\
		ft_lstdelone.c			\
		ft_lstdel.c				\
		ft_lstadd.c				\
		ft_lstiter.c			\
		ft_lstmap.c				\
		ft_islowercase.c		\
		ft_isuppercase.c		\
		ft_swap.c				\
		ft_strrev.c				\
		ft_lstsize.c			\
		ft_range.c				\
		ft_iseven.c				\
		ft_isodd.c				\
		ft_abs.c				\
		ft_strjoin_free.c		\
		ft_ullitoa_base.c		\
		ft_strlower.c			\
		ft_lltoa_base.c			\
		ft_ltoa_base.c			\
		ft_itoa_base.c			\
		ft_uitoa_base.c			\
		ft_ulitoa_base.c		\
		ft_strisalpha.c 		\
		ft_rec_c.c				\
		ft_pow.c				\
		ft_fdtoa.c				\
		ft_free_str.c			\
		ft_free_tab.c			\
		ft_check_zero_d.c		\
		ft_parse_type.c			\
		ft_type_char.c			\
		ft_dis.c				\
		ft_parse_width.c		\
		ft_type_conv.c			\
		ft_fl_ok.c				\
		ft_parsing.c			\
		ft_type_float.c			\
		ft_float_expo.c			\
		ft_printf.c				\
		ft_type_int.c			\
		ft_float_tools.c		\
		ft_sharp.c				\
		ft_type_percent.c		\
		ft_free_arg.c			\
		ft_sign_float.c			\
		ft_type_pointer.c		\
		ft_get_sign.c			\
		ft_sp_switch_u.c		\
		ft_type_string.c		\
		ft_inf_nan.c			\
		ft_space_d.c			\
		ft_unsigned.c			\
		ft_parse_flag.c			\
		ft_space_float.c		\
		ft_width_float.c		\
		ft_parse_len.c			\
		ft_space_u.c			\
		ft_parse_precision.c	\
		ft_spec_zero_u.c		\
		get_next_line.c			\
		ft_get_fd.c

OBJECT = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = includes/

all: $(NAME)

$(NAME): $(OBJECT) $(HEADER)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

%.o: %.c
	@gcc $(FLAGS) -o $@ -c $< -I $(HEADER)

clean:
	@/bin/rm -f $(OBJECT)

fclean : clean
	@/bin/rm -f $(NAME)

re: fclean all
