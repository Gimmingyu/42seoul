/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 21:05:05 by taehokim          #+#    #+#             */
/*   Updated: 2020/07/17 21:05:05 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	print_string_l(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_number(int i)
{
	char	c;

	if (i == 0)
		return ;
	print_number(i / 10);
	c = i % 10 + '0';
	write(1, &c, 1);
}

void	ft_show_tab(t_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		print_string_l(par[i].str);
		if (par[i].size == 0)
			write(1, "0", 1);
		else
			print_number(par[i].size);
		write(1, "\n", 1);
		print_string_l(par[i].copy);
		i++;
	}
}
