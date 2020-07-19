/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:21:41 by jipark            #+#    #+#             */
/*   Updated: 2020/02/12 21:43:21 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		g_col = 0;
int		g_row = 0;
int		g_max = 0;
int		**g_map;
int		g_new_line_flag = 0;
int		g_error_flag = 0;
char	*g_char_arr;
char	*g_buf;
int		g_buf_flag = 0;

void	print_map(void)
{
	char	c;
	int		i;
	int		j;

	if (g_new_line_flag)
		write(1, "\n", 1);
	if (!g_new_line_flag)
		g_new_line_flag = 1;
	i = 0;
	while (i < g_row)
	{
		j = 0;
		while (j < g_col)
		{
			c = g_map[i][j];
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	get_solution(void)
{
	int first_max_index[2];

	find_first_big_square(first_max_index);
	draw_answer_square(first_max_index);
	convert_int_to_char();
	print_map();
	get_free();
	g_row = 0;
	g_col = 0;
	g_max = 0;
	g_error_flag = 0;
}

void	get_free(void)
{
	int i;

	i = 0;
	if (g_error_flag != 1)
	{
		if (g_error_flag == 0 || g_error_flag == 2 || g_error_flag == 3)
			free(g_char_arr);
		if (g_error_flag == 0 || g_error_flag == 3)
		{
			while (i < g_row)
			{
				free(g_map[i]);
				i++;
			}
			free(g_map);
		}
	}
	if (g_buf_flag)
		free(g_buf);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (g_new_line_flag)
		write(1, "\n", 1);
	if (!g_new_line_flag)
		g_new_line_flag = 1;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

int		main(int argc, char *argv[])
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	if (argc == 1)
	{
		if (!get_std_input(c, 0))
		{
			handle_error();
			while (read(0, &c, sizeof(char)) && c != '\n')
			{
			}
		}
		else
			get_solution();
	}
	else
		while (++i < argc)
			if (!parse_file(argv[i]))
				handle_error();
			else
				get_solution();
	return (0);
}
