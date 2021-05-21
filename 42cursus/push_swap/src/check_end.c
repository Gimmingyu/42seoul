/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:27:58 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/17 18:28:00 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_pivot_tab_dn(t_stack *a, int pvt)
{
	int i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->tab[i] > pvt)
			return (-1);
		i++;
	}
	return (1);
}

int		check_pivot_tab_up(t_stack *a, int pvt)
{
	int i;

	i = 0;
	while (i + 1 < a->size)
	{
		if (a->tab[i] < pvt)
			return (-1);
		i++;
	}
	return (1);
}

int		check_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
			return (-1);
		i++;
	}
	return (1);
}

int		check_valid(t_stack *a, t_stack *b)
{
	int i;

	i = 0;
	if (b->size > 0)
		return (-1);
	while (i + 1 < a->size)
	{
		if (a->tab[i] > a->tab[i + 1])
			return (-1);
		i++;
	}
	return (1);
}
