/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:51:53 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/17 17:51:55 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_pivot(t_stack *stack, int pivot)
{
	int i;

	i = stack->size;
	stack->tab[i] = pivot;
	stack->size = stack->size + 1;
}

int		get_pivot(t_stack *stack)
{
	int i;

	i = (stack->size / 2);
	return (i);
}

int		get_med(t_stack *tmp, int i, int j, int e_inf)
{
	int e_sup;
	int res;

	if (tmp->size % 2 == 1)
		res = 1;
	else
		res = 0;
	e_sup = 0;
	while (++i < tmp->size - 1)
	{
		while (++j < tmp->size - 1)
		{
			if (tmp->tab[i] < tmp->tab[j])
				e_inf++;
			else if (tmp->tab[i] > tmp->tab[j])
				e_sup++;
		}
		if (e_sup - e_inf == res)
			return (i);
		e_sup = 0;
		e_inf = 0;
		j = -1;
	}
	return (i);
}
