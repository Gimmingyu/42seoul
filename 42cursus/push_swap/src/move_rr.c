/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:28:49 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/17 18:28:50 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		move_rrev(t_stack *sub)
{
	int i;
	int tmp;

	i = sub->size - 1;
	if (i < 0)
		return (1);
	tmp = sub->tab[sub->size - 1];
	while (i > 0)
	{
		sub->tab[i] = sub->tab[i - 1];
		i--;
	}
	sub->tab[0] = tmp;
	return (1);
}

int				move_rrb(t_stack *a, t_stack *b)
{
	(void)a;
	move_rrev(b);
	return (1);
}

int				move_rra(t_stack *a, t_stack *b)
{
	(void)b;
	move_rrev(a);
	return (1);
}

int				move_rrr(t_stack *a, t_stack *b)
{
	move_rrev(a);
	move_rrev(b);
	return (1);
}
