/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:21:22 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/06 20:06:43 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// #include "ft_stock_str.h"

t_stock_str			get_struct(t_stock_str result, char *str, int size)
{
	int i;

	i = 0 - 1;
	result.size = size;
	result.str = str;
	while (++i < size + 1)
		result.copy[i] = result.str[i];
	return (result);
}

void				get_free(t_stock_str *result, int size)
{
	int i;

	i = 0 - 1;
	while (++i < size)
		free(result[i].copy);
	free(result);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			len;
	t_stock_str	*result;

	i = 0 - 1;
	if (!(result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (0);
	while (++i < ac)
	{
		len = 0;
		while (av[i][len] != 0)
			len++;
		if (!(result[i].copy = (char *)malloc(sizeof(char) * len + 1)))
		{
			get_free(result, i);
			return (0);
		}
		result[i] = get_struct(result[i], av[i], len);
	}
	result[i].size = 0;
	result[i].str = 0;
	result[i].copy = 0;
	return (result);
}
