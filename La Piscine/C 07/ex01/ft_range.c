/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 11:52:27 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 14:11:24 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	unsigned long long		length;
	unsigned long long		count;
	int						*arr;

	arr = 0;
	if (min >= max)
		return (arr);
	length = max - min;
	arr = malloc(sizeof(int) * length);
	count = 0;
	while (count < length)
	{
		arr[count] = min;
		min++;
		count++;
	}
	return (arr);
}
