/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jushin <jushin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:10:17 by jushin            #+#    #+#             */
/*   Updated: 2020/02/12 14:24:39 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "dict.h"
#include "ft_string.h"
#include "ft_string2.h"
#include "find_util.h"

/*
** function 'unit1' print first digit
*/

void	unit1(t_dict **hash, char c, int row)
{
	char	tmp[2];

	if (c != '0')
	{
		tmp[0] = c;
		tmp[1] = '\0';
		if (row != 0)
			write(1, " ", 1);
		find_in_dict(hash, tmp);
		print_digit(hash, 2);
	}
}

/*
** function 'unit2' print second digit
*/

void	unit2(t_dict **hash, char *unit_str, int col_len, int idx)
{
	char	tmp[3];

	tmp[2] = '\0';
	if (unit_str[idx] == '1')
	{
		if (col_len != 2)
			write(1, " ", 1);
		find_in_dict(hash, &unit_str[idx]);
	}
	else
	{
		tmp[0] = unit_str[idx];
		tmp[1] = '0';
		if (unit_str[idx] != '0')
		{
			if (col_len != 2)
				write(1, " ", 1);
			find_in_dict(hash, tmp);
		}
	}
}

/*
** function 'print_unit' print by unit
** unit is organized 3 digit
*/

void	print_unit(t_dict **hash, char *unit_str, int row, int col_len)
{
	int		idx;

	idx = 0;
	if (col_len - idx == 3)
	{
		unit1(hash, unit_str[idx], row);
		idx++;
	}
	if (col_len - idx == 2)
	{
		unit2(hash, unit_str, col_len, idx);
		if (unit_str[idx] != '1')
			idx++;
	}
	if (col_len == 1 || (col_len - idx == 1 && unit_str[idx] != '0'))
	{
		if (col_len != 1)
			write(1, " ", 1);
		find_in_dict(hash, &unit_str[idx]);
	}
}

/*
** function 'ft_print' print split_num by unit
*/

void	ft_print(t_dict **hash, char **split_num, int size)
{
	int		row;
	int		col_len;

	row = 0;
	while (row < size)
	{
		col_len = ft_strlen(split_num[row]);
		if (ft_strcmp(split_num[row], "000") == 0)
		{
			row++;
			continue;
		}
		print_unit(hash, split_num[row], row, col_len);
		print_digit(hash, (size - row - 1) * 3);
		row++;
	}
}

/*
** function 'find_num' find str from hash
*/

int		find_num(t_dict **hash, char *to_find)
{
	char	**split_num;
	int		size;
	int		idx;

	if (to_find[0] == '0')
	{
		idx = 0;
		while (to_find[idx] == '0' && idx < ft_strlen(to_find) - 1)
			idx++;
		to_find = &to_find[idx];
	}
	if (ft_strlen(to_find) > num_max_len(hash) + 2)
		return (-1);
	if (find_in_dict(hash, to_find) == -1)
	{
		size = split_by_digit(to_find);
		split_num = (char **)malloc(sizeof(char *) * size);
		put_by_digit(split_num, to_find, size);
		ft_print(hash, split_num, size);
		free_strs(split_num, size);
	}
	write(1, "\n", 1);
	return (0);
}
