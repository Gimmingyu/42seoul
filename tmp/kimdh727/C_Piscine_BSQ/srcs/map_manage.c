/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:04:16 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/12 22:42:51 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

void	map_init(t_bsq_map *map, char *map_info, int row, int col)
{
	int len;

	len = ft_strlen(map_info);
	map->row = row;
	map->col = col;
	map->empty = map_info[len - 3];
	map->obstacle = map_info[len - 2];
	map->full = map_info[len - 1];
	map->max = 0;
	map->max_row = 0;
	map->max_col = 0;
}

void	max_check(t_bsq_map *map)
{
	int	row;
	int	col;

	row = 0 - 1;
	while (++row < map->row)
	{
		col = 0 - 1;
		while (++col < map->col)
		{
			if (ft_is_max(&map->max, &map->map[row][col]))
			{
				map->max_row = row;
				map->max_col = col;
			}
		}
	}
}

void	calc_map(t_bsq_map *map, int row, int col)
{
	int min;

	if (map->map[row][col])
	{
		min = map->map[row - 1][col - 1];
		ft_min(&min, &map->map[row - 1][col]);
		ft_min(&min, &map->map[row][col - 1]);
		if (min)
			map->map[row][col] = min + 1;
	}
}

void	solve_map(t_bsq_map *map)
{
	int	row;
	int	col;

	row = 1 - 1;
	while (++row < map->row)
	{
		col = 1 - 1;
		while (++col < map->col)
		{
			calc_map(map, row, col);
		}
	}
}

void	pirnt_map(t_bsq_map *map)
{
	int row;
	int col;

	row = 0 - 1;
	while (++row < map->row)
	{
		col = 0 - 1;
		while (++col < map->col)
		{
			if (in_the_full(map, row, col))
				write(1, &map->full, 1);
			else if (map->map[row][col])
				write(1, &map->empty, 1);
			else
				write(1, &map->obstacle, 1);
		}
		write(1, "\n", 1);
	}
}
