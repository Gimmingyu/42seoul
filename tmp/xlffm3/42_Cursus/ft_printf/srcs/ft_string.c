/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 20:45:51 by jipark            #+#    #+#             */
/*   Updated: 2020/04/17 12:56:30 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_putstr(char *str, int str_len)
{
	int i;

	i = 0;
	while (i < str_len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	set_format_len(t_printf *format, int str_len)
{
	if (format->width < str_len)
		format->len += str_len;
	else
		format->len += format->width;
}

void	write_character(char c, t_printf *format)
{
	int width;

	width = (format->width) - 1;
	if (format->flag != '-')
	{
		while (width-- > 0)
			write(1, " ", 1);
	}
	write(1, &c, 1);
	if (format->flag == '-')
	{
		while (width-- > 0)
			write(1, " ", 1);
	}
	if (!format->width)
		format->len += 1;
	else
		format->len += (format->width);
}

int		set_str_len(char *str, t_printf *format)
{
	int str_len;

	if (format->is_dot == 1 ||
		(format->is_dot == 2 && !format->is_zeroed && !format->precision))
		str_len = 0;
	else if (format->is_dot && !format->is_zeroed &&
			format->is_width && !format->width && !format->flag)
		str_len = format->precision;
	else
	{
		str_len = ft_strlen(str);
		if (str_len >= format->precision && format->precision)
			str_len = str_len - (str_len - format->precision);
	}
	return (str_len);
}

void	write_string(char *str, t_printf *format)
{
	int str_len;
	int width;

	if (!str)
		str = "(null)";
	width = format->width;
	str_len = set_str_len(str, format);
	if (format->flag != '-')
	{
		while (width-- > str_len)
			write(1, " ", 1);
	}
	ft_putstr(str, str_len);
	if (format->flag == '-')
	{
		while (width-- > str_len)
			write(1, " ", 1);
	}
	set_format_len(format, str_len);
}
