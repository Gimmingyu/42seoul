/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 13:57:32 by jipark            #+#    #+#             */
/*   Updated: 2020/04/17 00:55:00 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_putnbr(int nb)
{
	char c;

	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (nb < 0)
		nb *= -1;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int		get_int_digits(int nbr)
{
	int len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int		get_zero_len(int nbr, t_printf *format, int *int_len)
{
	int zero_len;

	if (format->flag == '0' && !format->is_dot)
		zero_len = (format->width) - *int_len;
	else
	{
		zero_len = (format->precision) - *int_len;
		if (format->flag == '0' && format->is_dot && format->is_zeroed)
			zero_len = (format->width) - *int_len;
		else if (nbr < 0)
			zero_len++;
		if (zero_len > 0)
		{
			*int_len += zero_len;
			format->is_int_zero_flag = 1;
		}
	}
	return (zero_len);
}

void	write_int_white_space(t_printf *format, int int_len)
{
	int width;

	width = format->width;
	if (format->flag != '-' && !(format->flag == '0' && !format->is_dot))
	{
		if (!format->is_zeroed || !(format->flag == '0' && format->is_dot))
		{
			while (width-- > int_len)
			{
				write(1, " ", 1);
				format->len += 1;
			}
		}
	}
}

void	write_decimal(int nbr, t_printf *format)
{
	int int_len;
	int zero_len;

	int_len = get_int_digits(nbr);
	zero_len = get_zero_len(nbr, format, &int_len);
	write_int_white_space(format, int_len);
	if (nbr < 0)
		write(1, "-", 1);
	write_zero(format, zero_len, format->is_int_zero_flag);
	if (format->is_dot && !format->precision && !nbr)
	{
		if ((!format->is_width && format->is_zeroed) || format->is_zeroed)
			ft_putnbr(nbr);
		else if (format->width)
			write(1, " ", 1);
		else
			format->len -= 1;
	}
	else
		ft_putnbr(nbr);
	if (format->flag == '-')
		write_white_space(format, format->width, int_len);
	format->len += int_len;
}
