/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 10:16:05 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/16 10:16:24 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(int *numbers)
{
	int		i;
	char	temp;

	i = 0;
	while (i < 10)
	{
		temp = numbers[i] + '0';
		write(1, &temp, 1);
		i++;
	}
	write(1, "\n", 1);
}

int		is_possible(int pos, int m, int *queens)
{
	int i;
	int temp;

	i = 0;
	while (i < m)
	{
		if (pos == queens[i])
			return (0);
		temp = pos > queens[i] ? pos - queens[i] : queens[i] - pos;
		if (m - i == temp)
			return (0);
		i++;
	}
	return (1);
}

void	recursive_find(int m, int *queens, int *count)
{
	int i;

	if (m == 10)
	{
		(*count)++;
		print_numbers(queens);
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (is_possible(i, m, queens))
		{
			queens[m] = i;
			recursive_find(m + 1, queens, count);
		}
		i++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int queens[10];
	int count;

	count = 0;
	recursive_find(0, queens, &count);
	return (count);
}
