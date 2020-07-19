/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:43:24 by jipark            #+#    #+#             */
/*   Updated: 2020/04/17 14:13:15 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	atoi_asterisk(t_printf *format, va_list ap, int flag)
{
	int nbr;

	nbr = va_arg(ap, int);
	if (nbr < 0)
	{
		if (flag == 'w')
		{
			format->flag = '-';
			nbr *= -1;
		}
		else if (flag == 'p')
		{
			format->is_zeroed = 1;
			nbr = 0;
		}
	}
	if (flag == 'w')
	{
		format->is_width = 1;
		format->width = nbr;
	}
	else if (flag == 'p')
		format->precision = nbr;
}

void	check_flag(const char *str, int *i, t_printf *format)
{
	if (str[*i] == '-')
		format->flag = '-';
	else if (str[*i] == '0')
		format->flag = '0';
	else
		return ;
	while (str[*i] == (format->flag))
		*i += 1;
}

int		check_width(const char *str, int *i, t_printf *format, va_list ap)
{
	int res;

	if ((res = check_asterisk_validation(str, i, format, ap)) != 2)
		return (res);
	while (('0' <= str[*i] && str[*i] <= '9') || str[*i] == '-')
	{
		if (str[*i] != '-')
		{
			format->width = ((format->width) * 10) + (str[*i] - '0');
			format->is_width = 1;
		}
		*i += 1;
	}
	if ((res = check_asterisk_validation(str, i, format, ap)) != 2)
		return (res);
	return (1);
}

int		check_precision(const char *str, int *i, t_printf *format, va_list ap)
{
	if (str[*i] == '.')
	{
		*i += 1;
		format->is_dot = 1;
	}
	if (str[*i] == '*')
	{
		format->is_dot = 2;
		atoi_asterisk(format, ap, 'p');
		*i += 1;
		return (1);
	}
	while (('0' <= str[*i] && str[*i] <= '9'))
	{
		format->is_dot = 2;
		format->precision = ((format->precision) * 10) + (str[*i] - '0');
		*i += 1;
	}
	if (str[*i] == '.')
		return (0);
	return (1);
}

int		check_validation(va_list ap, const char *str, t_printf *format)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!skip_mod(str, &i))
			{
				init_t_printf(format);
				check_flag(str, &i, format);
				if (!check_width(str, &i, format, ap))
					return (0);
				if (!check_precision(str, &i, format, ap))
					return (0);
				if (!check_specifier(ap, str[i], format))
					return (0);
			}
		}
		i++;
	}
	va_end(ap);
	format->len = 0;
	return (1);
}
