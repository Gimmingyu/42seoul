/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 17:57:37 by jipark            #+#    #+#             */
/*   Updated: 2020/02/02 22:15:05 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "ft_backtracking.h"
#include "ft_verify_location.h"
#include "ft_process_input.h"

/*
**	The program displays 4 * 4 square map containing numbers.
**	Those numbers means the size of the each building.
**	The size belongs to the range of from 1 to 4, and it is
**	determined by the input string.
*/

/*
**	g_size means the length of the square.
**	g_map_cnt is used to count the number of available cases.
**	g_row_restriction and g_col_restriction is used to save
**	users's input, meaning row and column.
*/

int g_size = 4;
int g_map_cnt = 0;
int **g_row_restriction;
int **g_col_restriction;

/*
**	is_valid_input function checks the validation of user's
**	input string.
*/

int		is_valid_input(char *input)
{
	init_restriction_array();
	if (input[31] != '\0')
		return (0);
	input[31] = ' ';
	if (!set_restriction_array(input))
		return (0);
	if (!is_valid_number())
		return (0);
	return (1);
}

void	free_map_array(int **map_arr)
{
	int i;

	i = 0;
	while (i < g_size)
	{
		free(map_arr[i]);
		i++;
	}
	free(map_arr);
}

void	free_restriction_array(void)
{
	int i;

	i = 0;
	while (i < 2)
	{
		free(g_row_restriction[i]);
		free(g_col_restriction[i]);
		i++;
	}
	free(g_col_restriction);
	free(g_row_restriction);
}

int		main(int argc, char *argv[])
{
	int **map_arr;

	if (argc == 2)
	{
		if (!is_valid_input(argv[1]))
		{
			write(1, "Error\n", 6);
		}
		else
		{
			map_arr = get_map_array();
			dfs(map_arr, 0, 0);
			if (!g_map_cnt)
				write(1, "Error\n", 6);
			free_map_array(map_arr);
		}
		free_restriction_array();
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
