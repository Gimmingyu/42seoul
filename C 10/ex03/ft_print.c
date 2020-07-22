/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 15:55:23 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 00:28:04 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_print_offset_cnt(int i)
{
	int		k;
	int		len;

	k = 0;
	len = ft_check_length(i);
	while (k++ < g_len - len)
		write(1, "0", 1);
	if (i)
		ft_print_address(i);
}

void	ft_print_center_content(char *buf)
{
	int		k;
	int		cnt;

	k = 0;
	cnt = 0;
	write(1, " ", 1);
	while (k < 16 && buf[k] != '\0')
	{
		ft_print_hex_content(buf[k], k);
		k++;
	}
	if (k != 16)
	{
		while (cnt < 3 * (16 - k) - 1)
		{
			write(1, " ", 1);
			cnt++;
		}
	}
	write(1, "\n", 1);
	g_last_cnt = k;
}

void	ft_print_address(unsigned long long addr)
{
	unsigned char	tmp;

	if (addr >= 10 && addr < 16)
	{
		tmp = 'a' + ((addr % 16) - 10);
		write(1, &tmp, 1);
	}
	else if (addr < 10)
	{
		tmp = addr + 48;
		write(1, &tmp, 1);
	}
	else
	{
		ft_print_address(addr / 16);
		if (addr % 16 >= 10)
			tmp = 'a' + ((addr % 16) - 10);
		else
			tmp = (addr % 16) + 48;
		write(1, &tmp, 1);
	}
}

void	ft_print_raw_content(char *buf)
{
	int i;

	i = 0;
	write(1, "  |", 3);
	while (i < 16)
	{
		if (buf[i] <= 31 || buf[i] >= 127)
			write(1, ".", 1);
		else
			write(1, &buf[i], 1);
		i++;
	}
	write(1, "|", 1);
	write(1, "\n", 1);
}
