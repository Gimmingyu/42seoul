/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:56:27 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/24 11:57:44 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *arr, int i, int j)
{
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int		partition(int *arr, int pre, int rea)
{
	int pivot;
	int left;
	int right;

	pivot = arr[pre];
	left = pre;
	right = left;
	while (++right <= rea)
	{
		if (pivot > arr[right])
		{
			left++;
			swap(arr, left, right);
		}
	}
	arr[pre] = arr[left];
	arr[left] = pivot;
	return (left);
}

void	quick_sort(int *arr, int pre, int rea)
{
	int pivot_position;

	if (pre < rea)
	{
		pivot_position = partition(arr, pre, rea);
		quick_sort(arr, pre, pivot_position - 1);
		quick_sort(arr, pivot_position + 1, rea);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	quick_sort(tab, 0, size - 1);
}
