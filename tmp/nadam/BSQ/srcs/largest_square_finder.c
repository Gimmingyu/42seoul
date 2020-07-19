/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_square_finder.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:42:41 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/12 20:45:48 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "largest_square_finder.h"
#include "map_reader.h"

void		free_note(int **note, int line_num)
{
	int i;

	i = 0;
	while (i < line_num)
	{
		free(note[i]);
		i++;
	}
	free(note);
}

int			**prepare_note(struct s_map_info *info, int len)
{
	int row;
	int	**note;

	note = (int **)malloc(sizeof(int*) * info->line_num);
	if (note == 0)
		return (0);
	row = 0;
	while (row < info->line_num)
	{
		note[row] = (int *)malloc(sizeof(int) * len);
		if (note[row] == 0)
		{
			free_note(note, row);
			return (0);
		}
		row++;
	}
	return (note);
}

int			get_value(int **note, t_map_info *info, int r, int c)
{
	int val;
	int tmp;

	if (r == 0 || c == 0)
		val = (info->map[r][c] == info->obs) ? 0 : 1;
	else
	{
		if ((info->map)[r][c] == info->obs)
			val = 0;
		else
		{
			tmp = (note[r][c - 1] < note[r - 1][c]) ?
				note[r][c - 1] : note[r - 1][c];
			val = (note[r - 1][c - 1] < tmp) ? note[r - 1][c - 1] + 1 : tmp + 1;
		}
	}
	return (val);
}

t_answer	*find_answer_point(int **note, t_map_info *info, int len)
{
	int			col;
	int			row;
	t_answer	*ans;

	if ((ans = (t_answer *)malloc(sizeof(t_answer))) == 0)
		return (0);
	ans->size = 0;
	ans->col = 0;
	ans->row = 0;
	row = 0;
	while (row < info->line_num)
	{
		col = 0;
		while (col < len)
		{
			note[row][col] = get_value(note, info, row, col);
			ans->row = note[row][col] > ans->size ? row : ans->row;
			ans->col = note[row][col] > ans->size ? col : ans->col;
			ans->size = note[row][col] > ans->size ? note[row][col] : ans->size;
			col++;
		}
		row++;
	}
	return (ans);
}

t_answer	*find_largest_square(t_map_info *info)
{
	int			len;
	int			**note;
	t_answer	*ans;

	if (info == 0)
		return (0);
	len = ft_strlen((info->map)[0]);
	note = prepare_note(info, len);
	if (note == 0)
		return (0);
	ans = find_answer_point(note, info, len);
	free_note(note, info->line_num);
	return (ans);
}
