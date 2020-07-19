/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:58:12 by jipark            #+#    #+#             */
/*   Updated: 2020/02/02 22:22:32 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_backtracking.h"
#include "ft_verify_location.h"
#include "ft_main.h"

/*
**	print_map function is aimed to print the map_arr.
**	When this function runs, that means the increase of the g_map_cnt.
*/

void	print_map(int **map_arr)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < g_size)
	{
		j = 0;
		while (j < g_size - 1)
		{
			c = map_arr[i][j] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			j++;
		}
		c = map_arr[i][j] + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
		i++;
	}
	g_map_cnt += 1;
}

/*
**	dfs function fill the map_arr by using depth-first-search algorithm.
**	It also check the available element by using back-tracking and other
**	functions.
*/

void	dfs(int **map_arr, int row, int col)
{
	if (g_map_cnt == 1)
		return ;
	if (row == 3 && col == 4)
	{
		if (check_row_exception(map_arr, row))
			print_map(map_arr);
	}
	else if (row != 3 && col == 4)
		dfs(map_arr, row + 1, 0);
	else
		check_required_conditions(map_arr, row, col);
}

void	check_required_conditions(int **map_arr, int row, int col)
{
	int box_size;

	box_size = 1;
	while (box_size <= g_size)
	{
		map_arr[row][col] = box_size;
		if (is_possible_row(map_arr, row, col)
		&& is_possible_col(map_arr, row, col))
		{
			if (row == 3)
			{
				if (check_col_exception(map_arr, col))
					dfs(map_arr, row, col + 1);
			}
			else if (col == 3)
			{
				if (check_row_exception(map_arr, row))
					dfs(map_arr, row, col + 1);
			}
			else
				dfs(map_arr, row, col + 1);
		}
		box_size++;
	}
}
