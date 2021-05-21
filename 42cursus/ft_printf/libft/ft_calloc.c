/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:44:44 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:51:15 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*result;
	size_t	i;
	size_t	limit;

	if (number && size)
	{
		limit = number * size;
		if (limit % size != 0 || limit / size != number)
		{
			errno = ENOMEM;
			return (0);
		}
	}
	else
		limit = 1;
	result = (char *)malloc(limit);
	if (result)
	{
		i = -1;
		while (++i < limit)
			result[i] = 0;
	}
	return (result);
}
