/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohkim <seohkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 16:25:33 by seohkim           #+#    #+#             */
/*   Updated: 2020/07/06 20:44:21 by seohkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int mid;
	int pos;

	mid = size / 2;
	pos = 0;
	if (size % 2 == 0)
	{
		while (pos < mid)
		{
			ft_swap(&tab[pos], &tab[size - pos - 1]);
			pos++;
		}
	}
	else
	{
		while (pos <= mid)
		{
			ft_swap(&tab[pos], &tab[size - pos]);
			pos++;
		}
	}
}
