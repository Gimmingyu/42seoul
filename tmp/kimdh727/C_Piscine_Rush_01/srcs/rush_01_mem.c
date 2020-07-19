/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:35:20 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/02 18:54:41 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rush_01.h"

/*
** This FUNCTION use to global variable initializer
** memory allocation fit size using size value
*/

void	global_init(int size)
{
	int i;
	int j;

	g_num = size;
	g_map = (int **)malloc(sizeof(int *) * g_num);
	g_row = (int **)malloc(sizeof(int *) * g_num);
	g_col = (int **)malloc(sizeof(int *) * g_num);
	i = 0 - 1;
	while (++i < g_num)
	{
		g_map[i] = (int *)malloc(sizeof(int) * g_num);
		g_row[i] = (int *)malloc(sizeof(int) * g_num);
		g_col[i] = (int *)malloc(sizeof(int) * g_num);
		j = 0 - 1;
		while (++j < g_num)
		{
			g_map[i][j] = 0;
			g_row[i][j] = 0;
			g_col[i][j] = 0;
		}
	}
	g_flag = 0;
}

/*
** This FUNCTION use to free all memory allocation
*/

void	free_all(int **checker)
{
	int i;

	i = 0 - 1;
	while (++i < g_num * 2)
	{
		if (i < g_num)
		{
			free(g_map[i]);
			free(g_row[i]);
			free(g_col[i]);
		}
		free(checker[i]);
	}
	free(g_map);
	free(g_row);
	free(g_col);
	free(checker);
}
