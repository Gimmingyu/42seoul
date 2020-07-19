/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:11:00 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/02 02:48:42 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
// #include "ft_stock_str.h"

void	print_num(unsigned int nb)
{
	char print;

	if (nb >= 10)
		print_num(nb / 10);
	print = nb % 10 + '0';
	write(1, &print, 1);
}

void	print_int(int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		write(1, "-", 1);
	}
	print_num((unsigned int)nb);
	write(1, "\n", 1);
}

void	print_string(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0 - 1;
	while (par[++i].str)
	{
		print_string(par[i].str);
		print_int(par[i].size);
		print_string(par[i].copy);
	}
}
