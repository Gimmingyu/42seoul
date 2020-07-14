/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queen_puzzle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sieukim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:39:03 by sieukim           #+#    #+#             */
/*   Updated: 2020/07/14 02:36:05 by sieukim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_queens[10][10];

int		ft_queens_check(int row, int col);
int		ft_queens_dup(int row, int col);
void	ft_print_queens(void);

int		ft_ten_queens_puzzle(void)
{
	return (ft_queens_check(0, 0));
}

void	ft_print_queens(void)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (g_queens[i][j] == 1)
			{
				c = j + '0';
				write(1, &c, 1);
			}
			j++;
		}
		i++;
	}
}

int		ft_queens_check(int row, int col)
{
	int i;
	int count;

	count = 0;
	if (row == 9)
	{
		count++;
		ft_print_queens();
		return (count);
	}
	i = 0;
	while (i < 9)
	{
		g_queens[row][col] = 1;
		if (ft_queens_dup(row, col))
			ft_queens_check(row + 1, col);
		g_queens[row][col] = 0;
		i++;
	}
	return (0);
}

int		ft_queens_dup(int row, int col)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (i != row && g_queens[i][col] == 1)
			return (0);
		if (i != row && g_queens[i][col - 1] == 1)
			return (0);
		if (i != row && g_queens[i][col + 1] == 1)
			return (0);
		if (i != col && g_queens[row][i] == 1)
			return (0);
		if (i != col && g_queens[row - 1][i] == 1)
			return (0);
		if (i != col && g_queens[row + 1][i] == 1)
			return (0);
		i++;
	}
	return (1);
}
