/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:47:15 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 21:25:16 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	get_hex(int n)
{
	if (n < 10)
		return (n + '0');
	return (n + 87);
}

void			print_address(void *addr)
{
	unsigned char	address[17];
	int				index;
	long			temp;

	address[16] = ':';
	index = 15;
	temp = (long)addr;
	while (index >= 0)
	{
		address[index] = get_hex(temp % 16);
		temp /= 16;
		index--;
	}
	write(1, address, 17);
}

void			change_non_printable_and_print(void *addr, unsigned int size)
{
	unsigned char	temp;
	unsigned int	index;

	write(1, " ", 1);
	index = 0;
	while (index < size)
	{
		temp = *((unsigned char *)addr + index);
		if (temp >= 32 && temp <= 126)
			write(1, &temp, 1);
		else
			write(1, ".", 1);
		index++;
	}
	write(1, "\n", 1);
}

void			print_contents(void *addr, unsigned int size)
{
	unsigned char	temp_c[3];
	unsigned int	index;
	unsigned char	temp;

	index = 0;
	temp_c[0] = ' ';
	while (index < 16)
	{
		if (index < size)
		{
			temp = *((unsigned char *)addr + index);
			temp_c[1] = get_hex(temp / 16 % 16);
			temp_c[2] = get_hex(temp % 16);
		}
		else
		{
			temp_c[1] = ' ';
			temp_c[2] = ' ';
		}
		if (++index % 2 == 1)
			write(1, &temp_c, 3);
		else
			write(1, &temp_c[1], 2);
	}
	change_non_printable_and_print(addr, size);
}

void			*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int temp;
	unsigned int index;

	index = 0;
	temp = size / 16;
	while (index < temp)
	{
		print_address((unsigned char *)addr + (16 * index));
		print_contents((unsigned char *)addr + (16 * index), 16);
		index++;
	}
	temp = size % 16;
	print_address((unsigned char *)addr + size - temp);
	print_contents((unsigned char *)addr + size - temp, temp);
	return (addr);
}
