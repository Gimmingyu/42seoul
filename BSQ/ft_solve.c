/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 04:44:43 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/23 04:44:43 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_min(int diag, int up, int left)
{
	diag = diag > up ? up : diag;
	return ((diag > left ? left : diag) + 1);
}

void	set_max(t_map *info, int i, int j)
{
	if (info->map[i][j] > info->max)
	{
		info->max = info->map[i][j];
		info->max_x = j;
		info->max_y = i;
	}
}

void	find_square(t_map *info)
{
	int i;
	int j;

	i = 1;
	info->max = -1;
	while (i < info->y)
	{
		j = 1;
		while (j < info->x)
		{
			if (info->map[i][j] > 0)
			{
				info->map[i][j] = ft_min(info->map[i - 1][j - 1],
						info->map[i - 1][j], info->map[i][j - 1]);
				set_max(info, i, j);
			}
			j++;
		}
		i++;
	}
}
