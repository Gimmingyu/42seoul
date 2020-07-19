/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 14:01:05 by jipark            #+#    #+#             */
/*   Updated: 2020/04/17 14:34:44 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_print_memory(unsigned long long address)
{
	if (address >= 16)
		ft_print_memory(address / 16);
	write(1, &"0123456789abcdef"[address % 16], 1);
}

int		get_memory_digits(unsigned long long address, t_printf *format)
{
	int len;

	len = 0;
	if (!address)
	{
		if (format->is_dot == 1)
			return (2);
		return (3);
	}
	else
	{
		while (address != 0)
		{
			address /= 16;
			len++;
		}
	}
	return (len + 2);
}

void	write_memory(unsigned long long address, t_printf *format)
{
	int memory_len;
	int width;

	memory_len = get_memory_digits(address, format);
	width = format->width;
	if (format->flag != '-')
		write_white_space(format, width, memory_len);
	if (!address)
		ft_putstr("0x0", memory_len);
	else
	{
		write(1, "0x", 2);
		ft_print_memory(address);
	}
	if (format->flag == '-')
		write_white_space(format, width, memory_len);
	format->len += memory_len;
}
