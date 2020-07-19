/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:26:28 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/29 21:33:45 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_row[15];
int g_col[15];
int g_n = 10;

void	print_chessboard(void)
{
	int		i;
	char	print;

	i = 0 - 1;
	while (++i < g_n)
	{
		print = g_row[i] + '0';
		write(1, &print, 1);
	}
	write(1, "\n", 1);
}

int		check(int index_orig, int index_new)
{
	int row_diff;
	int col_diff;

	row_diff = (index_orig / g_n) - (index_new / g_n);
	col_diff = (index_orig % g_n) - (index_new % g_n);
	if (row_diff < 0)
		row_diff *= -1;
	if (col_diff < 0)
		col_diff *= -1;
	return (!(row_diff == col_diff));
}

void	backtracking(int cnt, int *result)
{
	int i;
	int j;

	if (cnt == g_n)
	{
		print_chessboard();
		*result = *result + 1;
		return ;
	}
	i = 0 - 1;
	while (++i < g_n)
		if (!g_col[i])
		{
			j = 0;
			while (j < cnt && check(g_n * g_row[j] + j, g_n * i + cnt))
				j++;
			if (j == cnt)
			{
				g_row[cnt] = i;
				g_col[i] = 1;
				backtracking(cnt + 1, result);
				g_col[i] = 0;
			}
		}
}

int		ft_ten_queens_puzzle(void)
{
	int i;
	int result;

	result = 0;
	i = 0 - 1;
	while (++i < g_n)
	{
		g_row[i] = 0;
		g_col[i] = 0;
	}
	backtracking(0, &result);
	return (result);
}
