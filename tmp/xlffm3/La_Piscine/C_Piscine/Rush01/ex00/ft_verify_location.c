/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_location.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:49:05 by jipark            #+#    #+#             */
/*   Updated: 2020/02/02 22:30:44 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_backtracking.h"
#include "ft_verify_location.h"
#include "ft_main.h"

/*
**	is_possible_row function is used to check if
**	the element is not duplicated in current row.
*/

int		is_possible_row(int **map_arr, int row, int col)
{
	int i;

	i = 0;
	while (i < col)
	{
		if (map_arr[row][i] == map_arr[row][col])
			return (0);
		i++;
	}
	return (1);
}

/*
**	is_possible_col function is used to check if
**	the element is not duplicated in current column.
*/

int		is_possible_col(int **map_arr, int row, int col)
{
	int i;

	i = 0;
	while (i < row)
	{
		if (map_arr[i][col] == map_arr[row][col])
			return (0);
		i++;
	}
	return (1);
}

/*
**	compare_restriction function will check if the visible boxes
**	from the side ((left and right) or (top and bottom)) matches
**	the restriction	from user input string.
**	It uses parameters came from check_col_exception and
**	check_row_exception.
*/

int		compare_restriction(int first, int last, int row, int col)
{
	if (row >= 0)
	{
		if (first == g_row_restriction[0][row]
		&& last == g_row_restriction[1][row])
			return (1);
	}
	else
	{
		if (first == g_col_restriction[0][col]
		&& last == g_col_restriction[1][col])
			return (1);
	}
	return (0);
}

/*
**	check_row_exception function is to find out current
**	visible boxes from row (left and right).
*/

int		check_row_exception(int **map_arr, int row)
{
	int i;
	int max_left;
	int max_right;
	int left_cnt;
	int right_cnt;

	right_cnt = 1;
	left_cnt = 1;
	i = 0;
	max_left = map_arr[row][0];
	max_right = map_arr[row][3];
	while (++i < 4)
	{
		if (map_arr[row][i] > max_left)
		{
			left_cnt++;
			max_left = map_arr[row][i];
		}
		if (map_arr[row][3 - i] > max_right)
		{
			right_cnt++;
			max_right = map_arr[row][3 - i];
		}
	}
	return (compare_restriction(left_cnt, right_cnt, row, -1));
}

/*
**	check_col_exception function is to find out current
**	visible boxes from column (top and bottom).
*/

int		check_col_exception(int **map_arr, int col)
{
	int i;
	int max_top;
	int max_bot;
	int top_cnt;
	int bot_cnt;

	top_cnt = 1;
	bot_cnt = 1;
	i = 0;
	max_top = map_arr[0][col];
	max_bot = map_arr[3][col];
	while (++i < 4)
	{
		if (map_arr[i][col] > max_top)
		{
			top_cnt++;
			max_top = map_arr[i][col];
		}
		if (map_arr[3 - i][col] > max_bot)
		{
			bot_cnt++;
			max_bot = map_arr[3 - i][col];
		}
	}
	return (compare_restriction(top_cnt, bot_cnt, -1, col));
}
