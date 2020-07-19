/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:41:23 by jipark            #+#    #+#             */
/*   Updated: 2020/02/12 21:43:22 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		get_value(int y, int x)
{
	int min;
	int left_num;
	int up_num;
	int left_up_num;

	if (y < 1 || x < 1)
		return (g_map[y][x]);
	else
	{
		left_num = g_map[y][x - 1];
		up_num = g_map[y - 1][x];
		left_up_num = g_map[y - 1][x - 1];
		min = left_num;
		if (min > up_num)
			min = up_num;
		if (min > left_up_num)
			min = left_up_num;
		return (min + 1);
	}
}

void	draw_answer_square(int first_max_index[2])
{
	int x;
	int y;

	x = 0;
	while (x < g_max)
	{
		y = 0;
		while (y < g_max)
		{
			g_map[y + first_max_index[0]][x + first_max_index[1]] = -1;
			y++;
		}
		x++;
	}
}

void	find_first_big_square(int first_max_index[2])
{
	int x;
	int y;

	y = -1;
	while (++y < g_row)
	{
		x = -1;
		while (++x < g_col)
			if (g_map[y][x] == 1)
			{
				g_map[y][x] = get_value(y, x);
				if (g_map[y][x] > g_max)
				{
					g_max = g_map[y][x];
					first_max_index[0] = y - (g_max - 1);
					first_max_index[1] = x - (g_max - 1);
				}
			}
	}
}

void	convert_int_to_char(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_row)
	{
		j = 0;
		while (j < g_col)
		{
			if (g_map[i][j] == 0)
				g_map[i][j] = g_char_arr[1];
			else if (g_map[i][j] >= 1)
				g_map[i][j] = g_char_arr[0];
			else if (g_map[i][j] == -1)
				g_map[i][j] = g_char_arr[2];
			j++;
		}
		i++;
	}
}
