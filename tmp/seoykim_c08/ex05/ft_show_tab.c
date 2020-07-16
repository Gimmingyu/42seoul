/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42Seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 09:26:11 by seoykim           #+#    #+#             */
/*   Updated: 2020/07/15 16:48:49 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void				ft_putstr(char *str)
{
	while (*str != 0)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int					ft_cur_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

void				append_first(char c, char *str)
{
	int	size;

	size = ft_cur_strlen(str) + 1;
	while (size >= 1)
	{
		str[size] = str[size - 1];
		size--;
	}
	str[size] = c;
}

void				ft_putnbr(unsigned int nbri)
{
	char	c[11];
	int		i;

	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	c[0] = 0;
	while (nbr > 0)
	{
		append_first(nbr % 10 + '0', c);
		nbr = nbr / 10;
	}
	i = 0;
	while (c[i] != 0)
		write(1, &c[i++], 1);
	write(1, "\n", 1);
}

void				ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = -1;
	while (par[++i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		ft_putstr(par[i].copy);
	}
}
