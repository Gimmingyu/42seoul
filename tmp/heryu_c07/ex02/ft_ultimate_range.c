/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 22:27:58 by heryu             #+#    #+#             */
/*   Updated: 2020/07/14 00:11:33 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		size;
	int		i;
	int		val;

	if (min >= max)
	{
		*range = (void*)(0);
		return (0);
	}
	size = max - min;
	*range = (int*)malloc(sizeof(int) * size);
	if (*range == (void*)(0))
		return (-1);
	i = 0;
	val = min;
	while (val < max)
	{
		(*range)[i] = val;
		i++;
		val++;
	}
	return (sizeof(int) * size);
}
