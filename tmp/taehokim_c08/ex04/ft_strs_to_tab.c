/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taehokim <taehokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 20:24:46 by taehokim          #+#    #+#             */
/*   Updated: 2020/07/17 20:24:46 by taehokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int			ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char		*ft_strdup(char *src)
{
	char	*result;
	int		i;

	if ((result = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))) == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

void		free_strs(t_stock_str *result, int now)
{
	int	i;

	i = 0;
	while (i < now)
	{
		free(result[i].copy);
		i++;
	}
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	c;
	t_stock_str	*result;

	if ((result = (t_stock_str *)malloc(
		sizeof(t_stock_str) * (ac + 1))) == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		c.size = ft_strlen(av[i]);
		if ((c.copy = ft_strdup(av[i])) == 0)
		{
			free_strs(result, i);
			return (0);
		}
		c.str = av[i];
		result[i] = c;
		i++;
	}
	c.str = 0;
	result[ac] = c;
	return (result);
}
