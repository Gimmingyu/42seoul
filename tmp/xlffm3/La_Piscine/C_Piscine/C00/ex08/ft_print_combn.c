/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:18:11 by jipark            #+#    #+#             */
/*   Updated: 2020/01/23 12:35:42 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_last(int *arr, int index)
{
	int i;

	i = index - 1;
	if (arr[i] != 9)
	{
		return (0);
	}
	while (i > 0)
	{
		if (arr[i] != arr[i - 1] + 1)
		{
			return (0);
		}
		i--;
	}
	return (1);
}

void	print_arr(int *arr, int index)
{
	char	tmp;
	int		i;

	i = 0;
	while (i < index)
	{
		tmp = (char)(arr[i] + 48);
		write(1, &tmp, 1);
		i++;
	}
	if (check_last(arr, index) == 0)
	{
		write(1, ", ", 2);
	}
}

void	get_combination(int *arr, int index, int n, int target)
{
	if (n == 0)
	{
		print_arr(arr, index);
	}
	else if (target == 10)
	{
		return ;
	}
	else
	{
		arr[index] = target;
		get_combination(arr, index + 1, n - 1, target + 1);
		get_combination(arr, index, n, target + 1);
	}
}

void	ft_print_combn(int n)
{
	int arr[10];
	int index;
	int target;
	int i;

	index = 0;
	target = 0;
	i = 0;
	while (i < 10)
	{
		arr[i] = i;
		i++;
	}
	get_combination(arr, index, n, target);
}
