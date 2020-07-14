/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:38:49 by mchae             #+#    #+#             */
/*   Updated: 2020/07/09 15:02:51 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char				*g_hex;

void				swap(char *base, int pivot, int index)
{
	int				temp;

	temp = base[pivot];
	base[pivot] = base[index];
	base[index] = temp;
}

void				ft_sort_int_tab(char *base, int size)
{
	int				index;
	int				pivot;

	pivot = 0;
	while (pivot < size)
	{
		index = pivot + 1;
		while (index < size)
		{
			if (base[pivot] > base[index])
				swap(base, pivot, index);
			index++;
		}
		pivot++;
	}
}

void				print(long long longnbr, int num)
{
	if (longnbr >= num)
		print(longnbr / num, num);
	write(1, &g_hex[longnbr % num], 1);
}

int					exception(char *base)
{
	int				i;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] == base[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

void				ft_putnbr_base(int nbr, char *base)
{
	int				size;
	long long		longnbr;
	int				i;

	g_hex = "0123456789abcdef";
	i = 0;
	size = 0;
	longnbr = (long long)nbr;
	while (base[size])
	{
		size++;
	}
	if (*base == '\0' || size == 1 || size > 16)
		return ;
	ft_sort_int_tab(base, size);
	if (exception(base))
		return ;
	if (longnbr < 0)
	{
		write(1, "-", 1);
		longnbr *= -1;
	}
	print(longnbr, size);
}
