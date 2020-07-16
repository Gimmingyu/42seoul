/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoykim <seoykim@student.42seul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:59:16 by seoykim           #+#    #+#             */
/*   Updated: 2020/07/15 20:36:21 by seoykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++ != 0)
		len++;
	return (len);
}

char				*ft_strcopy(char *str, int size)
{
	char	*newstr;
	char	*temp;

	if((newstr = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	temp = newstr;
	while (*str != 0)
		*newstr++ = *str++;
	*newstr = 0;
	return (temp);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *str;
	int			i;

	if (ac <= 0)
	{
		str = NULL;
		return (str);
	}
	if (!(str = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1))))
		return (str);
	i = 0;
	while (i < ac)
	{
		str[i].size = ft_strlen(av[i]);
		str[i].str = av[i];
		str[i].copy = ft_strcopy(av[i], str[i].size);
		i++;
	}
	str[ac].str = NULL;
	return (str);
}
