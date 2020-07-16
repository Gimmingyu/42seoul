/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongckim <yongckim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:42:20 by yongckim          #+#    #+#             */
/*   Updated: 2020/07/15 19:02:50 by yongckim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int size;
	int i;

	if (min >= max)
		return (0);
	size = max - min;
	if (!((*range) = (int *)malloc(sizeof(int) * size)))
		return (-1);
	i = 0;
	while (i < size)
	{
		*(range)[i] = min + i;
		i++;
	}
	return (size);
}
