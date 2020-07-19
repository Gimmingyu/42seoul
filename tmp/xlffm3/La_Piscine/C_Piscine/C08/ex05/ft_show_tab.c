/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 10:59:35 by jipark            #+#    #+#             */
/*   Updated: 2020/02/03 12:55:16 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	write_size(int num)
{
	unsigned int	tmp;
	char			c;

	if (num < 0)
	{
		write(1, "-", 1);
		tmp = num * -1;
	}
	else
		tmp = num;
	if (tmp >= 10)
		write_size(tmp / 10);
	c = (tmp % 10) + '0';
	write(1, &c, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;
	int j;

	i = 0;
	while (par[i].str != 0)
	{
		j = 0;
		while (par[i].str[j] != '\0')
			write(1, &par[i].str[j++], 1);
		write(1, "\n", 1);
		write_size(par[i].size);
		write(1, "\n", 1);
		j = 0;
		while (par[i].copy[j] != '\0')
			write(1, &par[i].copy[j++], 1);
		write(1, "\n", 1);
		i++;
	}
}
