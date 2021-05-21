/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:28:57 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/17 18:28:58 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		move_s(t_stack *sub)
{
	int tmp;

	tmp = sub->tab[0];
	if (sub->size > 1)
	{
		sub->tab[0] = sub->tab[1];
		sub->tab[1] = tmp;
	}
	return (1);
}

int				move_sb(t_stack *a, t_stack *b)
{
	(void)a;
	move_s(b);
	return (1);
}

int				move_sa(t_stack *a, t_stack *b)
{
	(void)b;
	move_s(a);
	return (1);
}

int				move_ss(t_stack *a, t_stack *b)
{
	move_s(a);
	move_s(b);
	return (1);
}
