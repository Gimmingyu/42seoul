/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:27:43 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/13 19:40:09 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	map_set(t_bsq_map *map, char **map_file)
{
	int	i;
	int	j;

	i = 0 - 1;
	while (++i < map->row)
	{
		j = 0 - 1;
		while (++j < map->col)
		{
			if (map_file[i + 1][j] == map->empty)
				map->map[i][j] = 1;
			else if (map_file[i + 1][j] == map->obstacle)
				map->map[i][j] = 0;
		}
	}
}

void	map_memory(t_bsq_map *map)
{
	int	i;

	if (!(map->map = (int **)malloc(sizeof(int *) * map->row)))
	{
		g_flag |= 0x1000;
		return ;
	}
	i = 0 - 1;
	while (++i < map->row)
	{
		if (!(map->map[i] = (int *)malloc(sizeof(int) * map->col)))
		{
			g_flag |= 0x2000;
			return ;
		}
	}
}

void	free_map(t_bsq_map *map)
{
	int i;

	i = 0 - 1;
	while (++i < map->row)
	{
		free(map->map[i]);
	}
	free(map->map);
	if (g_flag & 0x3000)
		write(1, "map error\n", 10);
}

void	solve_bsq(char **map_data)
{
	t_bsq_map	map;
	int			row;
	int			col;

	row = check_info(map_data[0]);
	col = same_row_len(map_data, row);
	map_init(&map, map_data[0], row, col);
	map_memory(&map);
	if (g_flag & 0x2000)
	{
		free_map(&map);
		return ;
	}
	map_set(&map, map_data);
	solve_map(&map);
	max_check(&map);
	pirnt_map(&map);
	free_map(&map);
}

void	bsq(int argc, char *argv[])
{
	int		i;
	int		fd;
	char	**map_file;

	fd = 0;
	i = (argc == 1) ? 0 - 1 : 1 - 1;
	while (++i < argc)
	{
		g_flag = 0;
		if ((fd = (argc == 1) ? 0 : open(argv[i], O_RDONLY)) == -1)
			write(1, "map error\n", 10);
		else
		{
			if ((map_file = read_map(make_buf(fd))))
			{
				solve_bsq(map_file);
				free_split(ft_strarrlen(map_file), map_file);
			}
			else
				write(1, "map error\n", 10);
			close(fd);
		}
		if (i < argc - 1)
			write(1, "\n", 1);
	}
}
