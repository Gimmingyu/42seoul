/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:43:47 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/30 22:05:36 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	range;
	int				*arr;

	if (min >= max)
		return (0);
	range = max - min;
	arr = (int *)malloc(sizeof(int) * range);
	while (range--)
		arr[range] = (int)(min + range);
	return (arr);
}
