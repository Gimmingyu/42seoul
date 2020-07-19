/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:44:28 by jipark            #+#    #+#             */
/*   Updated: 2020/01/30 19:49:01 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	unsigned long long length;
	unsigned long long count;

	*range = 0;
	if (min >= max)
		return (0);
	length = max - min;
	*range = malloc(sizeof(int) * length);
	if (*range == 0)
		return (-1);
	count = 0;
	while (count < length)
	{
		(*range)[count] = min;
		min++;
		count++;
	}
	return (length);
}
