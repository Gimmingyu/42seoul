/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:53:08 by jipark            #+#    #+#             */
/*   Updated: 2020/01/27 15:14:44 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	print_hex_content(char *addr, int k, int i, int size)
{
	unsigned char	tmp;
	int				count;
	int				j;

	tmp = (unsigned char)addr[k];
	count = 16 - (k - i + 1);
	if (0 <= addr[k] && addr[k] < 16)
		write(1, "0", 1);
	print_address(tmp);
	if (k % 2 != 0)
		write(1, " ", 1);
	if (k == size - 1)
	{
		if (k % 2 == 0)
			write(1, " ", 1);
		j = 0;
		while (j++ < (count * 2) + (count / 2))
			write(1, " ", 1);
	}
}

void	print_content(char *arr, int k)
{
	if (arr[k] <= 31 || arr[k] >= 127)
		write(1, ".", 1);
	else
		write(1, &arr[k], 1);
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

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	length;

	i = 0;
	while (i < size)
	{
		k = 0;
		length = check_length((unsigned long long)&((char *)addr)[i]);
		while (k++ < 16 - length)
			write(1, "0", 1);
		print_address((unsigned long long)&((char *)addr)[i]);
		write(1, ": ", 2);
		k = 0;
		while (k < 16 && i + k < size)
			print_hex_content((char *)addr, i + (k++), i, (int)size);
		k = 0;
		while (k < 16 && i + k < size)
			print_content((char *)addr, i + (k++));
		write(1, "\n", 1);
		i += 16;
	}
	return ((void *)addr);
}
