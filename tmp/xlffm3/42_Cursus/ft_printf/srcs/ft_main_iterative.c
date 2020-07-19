/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_iterative.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 14:56:13 by jipark            #+#    #+#             */
/*   Updated: 2020/04/17 14:30:38 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	init_t_printf(t_printf *format)
{
	format->flag = 0;
	format->width = 0;
	format->is_dot = 0;
	format->is_width = 0;
	format->precision = 0;
	format->is_zeroed = 0;
	format->is_int_zero_flag = 0;
}

int		check_asterisk_validation(const char *str, int *i,
									t_printf *format, va_list ap)
{
	if (str[*i] == '*')
	{
		atoi_asterisk(format, ap, 'w');
		*i += 1;
		if (!format->width && !format->flag)
		{
			format->flag = '0';
			return (2);
		}
		else
		{
			if ('0' <= str[*i] && str[*i] <= '9')
				return (0);
			return (1);
		}
	}
	return (2);
}

int		check_specifier(va_list ap, const char c, t_printf *format)
{
	if (c == 'd' || c == 'i')
		va_arg(ap, int);
	else if (c == 'u' || c == 'x' || c == 'X')
		va_arg(ap, unsigned int);
	else if (c == 'c')
	{
		if (format->is_dot == 2)
			return (0);
		va_arg(ap, int);
	}
	else if (c == 'p')
	{
		if (format->is_dot == 2)
			return (0);
		va_arg(ap, unsigned long long);
	}
	else if (c == 's')
		va_arg(ap, char *);
	else
		return (0);
	return (1);
}

void	classify_specifier(va_list ap, const char c, t_printf *format)
{
	if (c == 'd' || c == 'i')
		write_decimal(va_arg(ap, int), format);
	else if (c == 'u')
		write_unsigned_int(va_arg(ap, unsigned int), format, 10, 0);
	else if (c == 'x')
		write_unsigned_int(va_arg(ap, unsigned int), format, 16, 0);
	else if (c == 'X')
		write_unsigned_int(va_arg(ap, unsigned int), format, 16, 1);
	else if (c == 'p')
		write_memory(va_arg(ap, unsigned long long), format);
	else if (c == 'c')
		write_character((char)va_arg(ap, int), format);
	else if (c == 's')
		write_string(va_arg(ap, char *), format);
}

void	get_result(const char *str, t_printf *format, va_list ap)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!write_mod(str, &i, format))
			{
				init_t_printf(format);
				check_flag(str, &i, format);
				check_width(str, &i, format, ap);
				check_precision(str, &i, format, ap);
				classify_specifier(ap, str[i], format);
			}
		}
		else
		{
			write(1, &str[i], 1);
			format->len += 1;
		}
		i++;
	}
}
