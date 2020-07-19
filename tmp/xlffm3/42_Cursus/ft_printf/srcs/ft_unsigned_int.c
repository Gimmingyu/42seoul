/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 19:09:40 by jipark            #+#    #+#             */
/*   Updated: 2020/04/17 12:57:33 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_convert_base(unsigned int nbr, unsigned int base, int bold_flag)
{
	if (nbr >= base)
		ft_convert_base(nbr / base, base, bold_flag);
	if (bold_flag)
		write(1, &"0123456789ABCDEF"[nbr % base], 1);
	else
		write(1, &"0123456789abcdef"[nbr % base], 1);
}

int		get_unsigned_int_digits(unsigned int nbr, int base)
{
	int len;

	len = 0;
	if (!nbr)
		len++;
	while (nbr != 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}

int		get_unsigned_zero_len(t_printf *format, int *u_int_len)
{
	int zero_len;

	if (format->flag == '0' && !format->is_dot)
		zero_len = (format->width) - *u_int_len;
	else
	{
		zero_len = (format->precision) - *u_int_len;
		if (format->flag == '0' && format->is_dot && format->is_zeroed)
			zero_len = (format->width) - *u_int_len;
		if (zero_len > 0)
		{
			*u_int_len += zero_len;
			format->is_int_zero_flag = 1;
		}
	}
	return (zero_len);
}

void	write_unsigned_int(unsigned int nbr, t_printf *format,
							int base, int bold)
{
	int u_int_len;
	int zero_len;

	u_int_len = get_unsigned_int_digits(nbr, base);
	zero_len = get_unsigned_zero_len(format, &u_int_len);
	write_int_white_space(format, u_int_len);
	write_zero(format, zero_len, format->is_int_zero_flag);
	if (format->is_dot && !format->precision && !nbr)
	{
		if ((!format->is_width && format->is_zeroed) || format->is_zeroed)
			ft_convert_base(nbr, base, bold);
		else if (format->width)
			write(1, " ", 1);
		else
			format->len -= 1;
	}
	else
		ft_convert_base(nbr, base, bold);
	if (format->flag == '-')
		write_white_space(format, format->width, u_int_len);
	format->len += u_int_len;
}
