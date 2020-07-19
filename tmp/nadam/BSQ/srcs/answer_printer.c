/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   answer_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:34:50 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/11 20:07:40 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "largest_square_finder.h"
#include "map_reader.h"

void	mark_largest_square(t_map_info *info, t_answer *ans)
{
	int row;
	int col;

	row = 0;
	while (row < ans->size)
	{
		col = 0;
		while (col < ans->size)
		{
			(info->map)[ans->row - row][ans->col - col] = info->mark;
			col++;
		}
		row++;
	}
}

void	print_answer(t_map_info *info)
{
	int row;
	int col;

	row = 0;
	while (row < info->line_num)
	{
		col = 0;
		while ((info->map)[row][col] != '\0')
		{
			write(1, &((info->map)[row][col]), 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
