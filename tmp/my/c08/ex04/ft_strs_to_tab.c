/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:20:38 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/16 15:05:26 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					get_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*str_cpy(char *str, int len)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

t_stock_str			*get_stock_str(t_stock_str *tab, char *str)
{
	tab->str = str;
	tab->size = get_len(str);
	tab->copy = str_cpy(str, tab->size);
	if (tab->copy == 0)
		return (0);
	return (tab);
}

void				free_tab(t_stock_str *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	t_stock_str	*temp;
	int			i;

	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == 0)
		return (0);
	result[ac].str = 0;
	i = 0;
	while (i < ac)
	{
		temp = get_stock_str(result + i, av[i]);
		if (temp == 0)
		{
			free_tab(result, i);
			return (0);
		}
		i++;
	}
	return (result);
}
