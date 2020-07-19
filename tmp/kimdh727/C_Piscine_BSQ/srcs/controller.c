/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:57:15 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/11 22:47:12 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_min(int *min, int *cmp)
{
	if (*min > *cmp)
		*min = *cmp;
}

int		ft_is_max(int *max, int *cmp)
{
	if (*max < *cmp)
	{
		*max = *cmp;
		return (1);
	}
	return (0);
}

int		in_the_full(t_bsq_map *map, int row, int col)
{
	return (row <= map->max_row && row >= map->max_row - map->max + 1 &&
			col <= map->max_col && col >= map->max_col - map->max + 1);
}

int		is_printable(char *str)
{
	int	i;

	i = 0 - 1;
	while (str[++i])
	{
		if (str[i] < 32 && str[i] > 126)
			return (0);
	}
	return (1);
}

int		is_map(char *str, char empty, char obstacle)
{
	int i;

	i = 0 - 1;
	while (str[++i])
	{
		if (!(str[i] == empty || str[i] == obstacle))
			return (0);
	}
	return (1);
}
