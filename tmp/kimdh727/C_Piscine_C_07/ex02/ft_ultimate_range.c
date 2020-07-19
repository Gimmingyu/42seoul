/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:54:23 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/31 00:48:35 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int i;

	if (min >= max)
		return (0);
	len = max - min;
	if (!((*range) = (int *)malloc(sizeof(int) * len)))
		return (-1);
	i = 0 - 1;
	while (++i < len)
		(*range)[i] = min + i;
	return (len);
}
