/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 17:38:42 by jipark            #+#    #+#             */
/*   Updated: 2020/02/12 21:43:24 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		allocate_g_map(void)
{
	int i;

	i = 0;
	if (!(g_map = (int **)malloc(sizeof(int *) * g_row)))
		return (0);
	while (i < g_row)
	{
		if (!(g_map[i] = (int *)malloc(sizeof(int) * g_col)))
			return (0);
		i++;
	}
	return (1);
}

int		init_g_map(int file, int i)
{
	char	c;
	int		index;

	index = 0;
	while (read(file, &c, sizeof(char)))
		if (c == '\n')
		{
			if (i != g_col || g_col == 0)
				return (0);
			index++;
			i = 0;
		}
		else
		{
			if (c == g_char_arr[0])
				g_map[index][i] = 1;
			else if (c == g_char_arr[1])
				g_map[index][i] = 0;
			else
				return (0);
			i++;
		}
	if (index != g_row || g_row == 0)
		return (0);
	return (1);
}

int		extract_char(char *name, int cnt)
{
	char	c;
	int		i;
	int		index;
	int		file;

	i = 0;
	index = 0;
	if ((file = open(name, O_RDONLY)) < 0)
		return (0);
	if (!(g_char_arr = (char *)malloc(sizeof(char) * 3)))
		return (0);
	while (read(file, &c, sizeof(char)) && c != '\n')
	{
		if (i < cnt - 3)
			g_row = (g_row * 10) + c - '0';
		else
		{
			g_char_arr[index] = c;
			index++;
		}
		i++;
	}
	while (read(file, &c, sizeof(char)) && c != '\n')
		g_col++;
	return (1);
}

int		parse_file(char *name)
{
	char	c;
	int		file;
	int		cnt;

	cnt = 0;
	g_error_flag = 1;
	if ((file = open(name, O_RDONLY)) < 0)
		return (0);
	while (read(file, &c, sizeof(char)) && c != '\n')
		cnt++;
	if (!extract_char(name, cnt))
		return (0);
	g_error_flag = 2;
	if (!allocate_g_map())
		return (0);
	g_error_flag = 3;
	if (!check_row_exception(name))
		return (0);
	if (!check_duplicate_char())
		return (0);
	if (!init_g_map(file, 0))
		return (0);
	return (1);
}

int		check_row_exception(char *name)
{
	int		file;
	int		cnt;
	char	c;

	cnt = 0;
	if ((file = open(name, O_RDONLY)) < 0)
		return (0);
	while (read(file, &c, sizeof(char)))
		if (c == '\n')
			break ;
	while (read(file, &c, sizeof(char)))
		if (c == '\n')
			cnt++;
	if (cnt != g_row)
		return (0);
	return (1);
}
