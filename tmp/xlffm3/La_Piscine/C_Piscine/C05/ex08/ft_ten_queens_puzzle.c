/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 20:47:33 by jipark            #+#    #+#             */
/*   Updated: 2020/01/29 11:12:12 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_position(int *col, int number)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < number)
	{
		tmp = col[i] + '0';
		write(1, &tmp, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		get_abs(int number)
{
	if (number < 0)
		return (-1 * number);
	return (number);
}

int		is_possible(int row, int *col)
{
	int i;

	i = 0;
	while (i < row)
	{
		if (col[i] == col[row])
			return (0);
		if (get_abs(i - row) == get_abs(col[i] - col[row]))
			return (0);
		i++;
	}
	return (1);
}

void	dfs(int row, int *col, int *answer, int number)
{
	int i;

	i = 0;
	if (row == number - 1)
	{
		*answer += 1;
		print_position(col, number);
	}
	else
	{
		while (i < number)
		{
			col[row + 1] = i;
			if (is_possible(row + 1, col))
			{
				dfs(row + 1, col, answer, number);
			}
			else
			{
				col[row + 1] = 0;
			}
			i++;
		}
	}
	col[row] = 0;
}

int		ft_ten_queens_puzzle(void)
{
	int col[10];
	int answer;
	int number;
	int row;

	answer = 0;
	number = 10;
	row = 0;
	while (row < number)
	{
		col[0] = row;
		dfs(0, col, &answer, number);
		row++;
	}
	return (answer);
}
