/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:55:26 by jipark            #+#    #+#             */
/*   Updated: 2020/02/02 22:31:07 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_process_input.h"
#include "ft_main.h"

/*
**	is_valid_number function will check the validation of input numbers.
**	The function only considers from 1 to 4 as proper numbers.
*/

int		is_valid_number(void)
{
	int i;
	int j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < g_size)
		{
			if (!(1 <= g_row_restriction[i][j]
			&& g_row_restriction[i][j] <= g_size))
				return (0);
			if (!(1 <= g_col_restriction[i][j]
			&& g_col_restriction[i][j] <= g_size))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/*
**	set_restriction_array function is aimed to put elements
**	into restriction_array according to the user's input string.
*/

int		set_restriction_array(char *input)
{
	int cnt;
	int i;

	cnt = 0;
	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
		{
			g_col_restriction[0][i / 2] = (int)(input[i] - '0');
			g_col_restriction[1][i / 2] = (int)(input[i + 8] - '0');
			g_row_restriction[0][i / 2] = (int)(input[i + 16] - '0');
			g_row_restriction[1][i / 2] = (int)(input[i + 24] - '0');
		}
		else
		{
			if (input[i] != ' ' || input[i + 8] != ' '
			|| input[i + 16] != ' ' || input[i + 24] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

/*
**	init_restriction_array is aimed to dynamically allocate
**	restriction arrays.
*/

void	init_restriction_array(void)
{
	int i;

	i = 0;
	g_row_restriction = (int **)malloc(sizeof(int *) * 2);
	g_col_restriction = (int **)malloc(sizeof(int *) * 2);
	while (i < 2)
	{
		g_row_restriction[i] = (int *)malloc(sizeof(int) * g_size);
		g_col_restriction[i] = (int *)malloc(sizeof(int) * g_size);
		i++;
	}
}

/*
**	get_map_array function is aimed to dynamically allocate
**	4 * 4 size two-dimensional array that will display answer.
*/

int		**get_map_array(void)
{
	int **map_arr;
	int i;
	int j;

	i = 0;
	map_arr = (int **)malloc(sizeof(int *) * g_size);
	while (i < 4)
	{
		map_arr[i] = (int *)malloc(sizeof(int) * g_size);
		j = 0;
		while (j < 4)
		{
			map_arr[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map_arr);
}
