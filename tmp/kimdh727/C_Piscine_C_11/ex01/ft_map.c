/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 21:33:07 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/06 21:54:10 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *map;

	if (!(map = (int *)malloc(sizeof(int) * length)))
		return (0);
	i = 0 - 1;
	while (++i < length)
		map[i] = f(tab[i]);
	return (map);
}
