/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:52:27 by jipark            #+#    #+#             */
/*   Updated: 2020/01/30 17:22:09 by jipark           ###   ########.fr       */
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
