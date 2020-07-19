/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:09:11 by jipark            #+#    #+#             */
/*   Updated: 2020/04/17 14:30:10 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_H_H
#	define FT_H_H
#	define ERROR -1
#	define OK 1

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

typedef struct	s_printf
{
	char	flag;
	int		width;
	int		is_dot;
	int		is_width;
	int		is_zeroed;
	int		precision;
	int		is_int_zero_flag;
	int		len;
}				t_printf;

int				ft_printf(const char *str, ...);

void			atoi_asterisk(t_printf *format, va_list ap, int flag);
void			check_flag(const char *str, int *i, t_printf *format);
int				check_width(const char *str, int *i,
							t_printf *format, va_list ap);
int				check_precision(const char *str, int *i,
								t_printf *format, va_list ap);
int				check_validation(va_list ap, const char *str, t_printf *format);

void			init_t_printf(t_printf *format);
int				check_asterisk_validation(const char *str, int *i,
										t_printf *format, va_list ap);
int				check_specifier(va_list ap, const char c, t_printf *format);
void			classify_specifier(va_list ap, const char c, t_printf *format);
void			get_result(const char *str, t_printf *format, va_list ap);

void			ft_putnbr(int nb);
int				get_int_digits(int nbr);
int				get_zero_len(int nbr, t_printf *format, int *int_len);
void			write_int_white_space(t_printf *format, int int_len);
void			write_decimal(int nbr, t_printf *format);

void			ft_convert_base(unsigned int nbr,
								unsigned int base, int bold_flag);
int				get_unsigned_int_digits(unsigned int nbr, int base);
int				get_unsigned_zero_len(t_printf *format, int *u_int_len);
void			write_unsigned_int(unsigned int nbr, t_printf *format,
				int base, int bold);

void			ft_print_memory(unsigned long long address);
int				get_memory_digits(unsigned long long address, t_printf *format);
void			write_memory(unsigned long long address, t_printf *format);

size_t			ft_strlen(const char *str);
int				set_str_len(char *str, t_printf *format);
void			ft_putstr(char *str, int str_len);
void			set_format_len(t_printf *format, int str_len);
void			write_character(char c, t_printf *format);
void			write_string(char *str, t_printf *format);

void			write_zero(t_printf *format, int zero_len, int flag);
void			write_white_space(t_printf *format, int width, int memory_len);
int				skip_mod(const char *str, int *i);
int				write_mod(const char *str, int *i, t_printf *format);
int				return_with_free(va_list ap, t_printf *format, int flag);

#	endif
