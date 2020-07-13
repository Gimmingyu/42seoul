/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:51:54 by heryu             #+#    #+#             */
/*   Updated: 2020/07/14 00:08:36 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*ret;
	int		size;
	int		i;
	int		val;

	if (min >= max)
		return (void*)(0);
	size = max - min;
	ret = (int*)malloc(sizeof(int) * size);
	if (ret == (void*)(0))
		return (void*)(0);
	i = 0;
	val = min;
	while (val < max)
	{
		ret[i] = val;
		i++;
		val++;
	}
	return (ret);
}
