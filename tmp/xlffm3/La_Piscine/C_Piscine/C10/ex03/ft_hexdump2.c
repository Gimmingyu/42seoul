/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 10:05:36 by jipark            #+#    #+#             */
/*   Updated: 2020/02/12 13:33:40 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	print_address(unsigned long long adress)
{
	unsigned char tmp;

	if (10 <= adress && adress < 16)
	{
		tmp = 'a' + ((adress % 16) - 10);
		write(1, &tmp, 1);
	}
	else if (adress < 10)
	{
		tmp = adress + 48;
		write(1, &tmp, 1);
	}
	else
	{
		print_address(adress / 16);
		if (adress % 16 >= 10)
			tmp = 'a' + ((adress % 16) - 10);
		else
			tmp = (adress % 16) + 48;
		write(1, &tmp, 1);
	}
}

int		check_length(unsigned long long address)
{
	int count;

	count = 0;
	while (address != 0)
	{
		address /= 16;
		count++;
	}
	return (count);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	print_hex_content(char buf, int k)
{
	unsigned char	tmp;

	tmp = (unsigned char)buf;
	if (0 <= buf && buf < 16)
		write(1, "0", 1);
	print_address(tmp);
	if (k != 15)
		write(1, " ", 1);
}

void	init_buf(char *buf)
{
	int i;

	i = 0;
	while (i < 17)
		buf[i++] = 0;
}
