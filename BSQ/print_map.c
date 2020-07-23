/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 05:07:05 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/23 05:07:05 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_square(t_map *info)
{
	int i;
	int j;
	int max;

	max = info->max;
	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < max)
		{
			info->map[info->max_y - j][info->max_x - i] = info->max;
			j++;
		}
		i++;
	}
}

void	max_one(t_map *info)
{
	int i;
	int j;

	i = 0;
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			if (info->map[i][j] == 1)
			{
				info->max_x = j;
				info->max_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	print_map(t_map *info)
{
	int i;
	int j;

	i = 0;
	if (info->max == 1)
		max_one(info);
	set_square(info);
	while (i < info->y)
	{
		j = 0;
		while (j < info->x)
		{
			if (info->map[i][j] == info->max &&
					(i <= info->max_y && j <= info->max_x))
				write(1, &info->full, 1);
			else if (info->map[i][j] == 0)
				write(1, &info->obst, 1);
			else
				write(1, &info->empty, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
