/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:39:49 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/27 22:53:42 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex_digit(unsigned long data, int digit, int n)
{
	unsigned char print;

	if (n < digit - 1)
		print_hex_digit(data >> 4, digit, n + 1);
	print = (data & 0xf);
	if (print < 10)
		print += '0';
	else
		print += ('a' - 10);
	write(1, &print, 1);
}

void	print_mem_address(char *addr, int offset)
{
	print_hex_digit((unsigned long)(addr + offset), 16, 0);
	write(1, ": ", 2);
}

void	print_hex(char *addr, int offset, unsigned int size)
{
	unsigned int	i;
	int				flag;

	i = 0;
	flag = 0;
	while (i < 16)
	{
		if (flag)
			write(1, "  ", 2);
		else
			print_hex_digit(addr[i + offset], 2, 0);
		if (i % 2 == 1)
			write(1, " ", 1);
		if (i == size - 1)
			flag = 1;
		i++;
	}
}

void	print_contents(char *addr, int offset, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (addr[i + offset] >= 32 && addr[i + offset] <= 126)
			write(1, &addr[i + offset], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		print_mem_address((char *)addr, i);
		print_hex((char *)addr, i, size - i);
		print_contents((char *)addr, i, size - i);
		i += 16;
	}
	return (addr);
}
