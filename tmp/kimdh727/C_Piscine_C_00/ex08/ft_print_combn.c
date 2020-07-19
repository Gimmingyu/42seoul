/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:38:02 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/23 13:33:15 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int g_max;

void	print_num(int n)
{
	char c;

	c = n + 48;
	write(1, &c, 1);
}

int		comp_combn_max(int *arr)
{
	int i;

	i = 0 - 1;
	while (++i < g_max)
	{
		if (arr[i] != 10 - g_max + i)
		{
			return (0);
		}
	}
	return (1);
}

void	backtrack(int cnt, int n, int *arr, int *visited)
{
	int i;

	if (cnt == g_max)
	{
		i = -1;
		while (++i < g_max)
			print_num(arr[i]);
		if (!comp_combn_max(arr))
			write(1, ", ", 2);
		return ;
	}
	i = n - 1;
	while (++i < 10)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			arr[cnt] = i;
			backtrack(cnt + 1, i, arr, visited);
			visited[i] = 0;
		}
	}
	return ;
}

void	ft_print_combn(int n)
{
	int arr[10];
	int visited[10];
	int i;

	g_max = n;
	i = -1;
	while (++i < 10)
		visited[i] = 0;
	backtrack(0, 0, arr, visited);
}
