/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:12:27 by jko               #+#    #+#             */
/*   Updated: 2020/01/24 10:32:10 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int n, int nums[])
{
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = nums[i] + 48;
		write(1, &c, 1);
		i++;
	}
	if (!(nums[0] == 10 - n && nums[n - 1] == 9))
	{
		c = ',';
		write(1, &c, 1);
		c = ' ';
		write(1, &c, 1);
	}
}

void	comb(int n, int m, int picked[])
{
	int i;

	if (n == m)
	{
		print(n, picked);
	}
	else
	{
		if (m == 0)
			i = 0;
		else
			i = picked[m - 1] + 1;
		while (i <= 9)
		{
			picked[m] = i;
			comb(n, m + 1, picked);
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	int picked[10];

	comb(n, 0, picked);
}
