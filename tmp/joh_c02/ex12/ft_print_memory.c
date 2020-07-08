/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:40:53 by joh               #+#    #+#             */
/*   Updated: 2020/07/08 20:16:31 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	arr_number(int num, int arr[], int index)
{
	if (num > 15)
	{
		arr_number(num / 16, arr, index + 1);
	}
	arr[index] = num % 16;
}

void	ft_print_hex(unsigned int num, int count)
{
	int arr[15];
	int index;

	index = -1;
	while (index++ < 14)
	{
		arr[index] = 0;
	}
	arr_number(num, arr, 0);
	index = -1;
	while (index++ < count)
	{
		write(1, &"0123456789abcdef"[arr[count - index]], 1);
	}
}

void	ft_print_char(char *c)
{
	if (*c >= ' ' && *c != 127)
		write(1, c, 1);
	else
		write(1, &".", 1);
}

void	ft_print_sub(void *all_addr, unsigned int size, char *curr_addr)
{
	int index;

	ft_print_hex((unsigned int)curr_addr, 14);
	write(1, &": ", 2);
	index = 0;
	while (index++ < 16)
	{
		if (all_addr + size <= (void *)(curr_addr + index - 1))
			write(1, &"  ", 2);
		else
			ft_print_hex((unsigned char)*(curr_addr + index - 1), 1);
		if (index % 2 == 0)
			write(1, &" ", 1);
	}
	index = 0;
	while (index++ < 16)
	{
		if (all_addr + size > (void *)(curr_addr + index - 1))
			ft_print_char((char *)curr_addr + index - 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*cur_addr;
	unsigned int	i;

	i = 0;
	cur_addr = (char *)addr;
	while ((void *)cur_addr < (addr + size))
	{
		ft_print_sub(addr, size, cur_addr);
		write(1, &"\n", 1);
		cur_addr += 16;
	}
	return (addr);
}
