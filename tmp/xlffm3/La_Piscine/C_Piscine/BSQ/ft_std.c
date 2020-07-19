/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 21:10:35 by jipark            #+#    #+#             */
/*   Updated: 2020/02/12 22:34:18 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		extract_std_char(char *g_buf, int cnt)
{
	int		i;
	int		index;
	int		j;

	i = 0;
	j = 0;
	index = 0;
	if (!(g_char_arr = (char *)malloc(sizeof(char) * 3)))
		return (0);
	while (g_buf[j] != '\0')
	{
		if (i < cnt - 3)
			g_row = (g_row * 10) + g_buf[j] - '0';
		else
		{
			g_char_arr[index] = g_buf[j];
			index++;
		}
		i++;
		j++;
	}
	return (1);
}

int		init_std_first_line(char *g_buf)
{
	int i;

	i = 0;
	while (g_buf[i] != '\0')
	{
		if (g_buf[i] == g_char_arr[0])
			g_map[0][i] = 1;
		else if (g_buf[i] == g_char_arr[1])
			g_map[0][i] = 0;
		else
			return (0);
		i++;
	}
	if (i != g_col || g_col == 0)
		return (0);
	return (1);
}

int		init_std_g_map(int i, int j, int index)
{
	char c;

	while (++i < g_row)
	{
		j = 0;
		while (read(0, &c, sizeof(char)) && c != '\n')
		{
			if (c == g_char_arr[0])
				g_map[index][j] = 1;
			else if (c == g_char_arr[1])
				g_map[index][j] = 0;
			else
				return (0);
			j++;
		}
		if (c == '\n')
			if (!(check_new_line_exception(j, &index)))
				return (0);
	}
	while (read(0, &c, sizeof(char)))
		index++;
	if (index != g_row || g_row == 0)
		return (0);
	return (1);
}

int		get_std_first_line(char *g_buf)
{
	char	c;
	int		i;

	i = 0;
	while (read(0, &c, sizeof(char)) && c != '\n')
	{
		g_buf[i] = c;
		i++;
	}
	g_buf[i] = '\0';
	return (i);
}

int		get_std_input(char c, int i)
{
	g_error_flag = 1;
	if (!allocate_g_buf())
		return (0);
	i = get_std_first_line(g_buf);
	if (!extract_std_char(g_buf, i))
		return (0);
	g_error_flag = 2;
	i = 0;
	while (read(0, &c, sizeof(char)) && c != '\n')
	{
		g_col++;
		g_buf[i] = c;
		i++;
	}
	g_buf[i] = '\0';
	if (!allocate_g_map())
		return (0);
	g_error_flag = 3;
	if (!check_duplicate_char())
		return (0);
	if (!init_std_first_line(g_buf))
		return (0);
	if (!init_std_g_map(0, 0, 1))
		return (0);
	return (1);
}
