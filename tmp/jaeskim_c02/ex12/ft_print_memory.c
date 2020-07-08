/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 23:15:59 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/08 11:54:58 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *g_hex;

void	ft_dec_to_hex(long long addr)
{
	if (addr > 15)
	{
		ft_dec_to_hex(addr / 16);
		ft_dec_to_hex(addr % 16);
	}
	else
		write(1, &g_hex[addr % 16], 1);
}

void	ft_print_hex(long long addr, int n)
{
	long long tmp;

	tmp = addr;
	while (tmp)
	{
		tmp /= 16;
		++n;
	}
	tmp = 0;
	while (n + tmp++ < 16)
		write(1, "0", 1);
	ft_dec_to_hex(addr);
	write(1, ":", 1);
}

void	ft_print_ascii(unsigned char *addr, unsigned int length)
{
	int i;

	i = 0;
	while ((unsigned int)i < length)
	{
		if (32 <= *(addr + i) && *(addr + i) < 127)
			write(1, addr + i, 1);
		else
			write(1, ".", 1);
		++i;
	}
}

void	ft_print_char_to_hex(unsigned char *addr, unsigned int length)
{
	int i;

	i = 0;
	while ((unsigned int)i < length)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, &g_hex[addr[i] / 16], 1);
		write(1, &g_hex[addr[i] % 16], 1);
		++i;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		write(1, "  ", 2);
		++i;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	length;
	int				i;

	g_hex = "0123456789abcdef";
	i = 0;
	while (size)
	{
		if (size / 16)
			length = 16;
		else
			length = size;
		ft_print_hex((long long)addr + i, 0);
		ft_print_char_to_hex(addr + i, length);
		write(1, " ", 1);
		ft_print_ascii(addr + i, length);
		write(1, "\n", 1);
		size -= length;
		i += 16;
	}
	return (addr);
}
