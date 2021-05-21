/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:25:57 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/17 17:26:01 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		get_pivot_five(t_stack *a)
{
	int i;

	i = a->size - 1;
	while (i > 0)
	{
		if (a->tab[0] < a->tab[i - 1])
			return (a->tab[i]);
		i--;
	}
	return (a->tab[a->size - 1]);
}

static void		sort_b_five(t_ab *arg)
{
	int i;
	int piv;
	int size;

	i = 0;
	piv = arg->b->tab[arg->b->size - 1];
	size = arg->b->size;
	while (i < size)
	{
		if (piv > arg->b->tab[0])
			move_check(arg, "rb", 1);
		else
			move_check(arg, "pa", 1);
		if (arg->a->size > 1 && arg->a->tab[0] > arg->a->tab[1])
			move_check(arg, "sa", 1);
		i++;
	}
}

static int		sort_a_five_next(int piv, t_ab *arg, int i, int size)
{
	if (arg->a->tab[0] == piv)
		return (size);
	if (piv < arg->a->tab[0])
		move_check(arg, "ra", 1);
	else
		move_check(arg, "pb", 1);
	if (arg->b->size > 1 && arg->b->tab[0] < arg->b->tab[1])
	{
		if (arg->b->size == 3
				&& arg->b->tab[0] < arg->b->tab[arg->b->size - 1])
			move_check(arg, "rb", 1);
		else
			move_check(arg, "sb", 1);
	}
	return (i);
}

static int		sort_a_five(t_ab *arg, int i, int size, int piv)
{
	if (check_pivot_tab_up(arg->a, piv) == 1
			&& piv == arg->a->tab[arg->a->size - 1])
	{
		move_check(arg, "rra", 1);
		return (0);
	}
	while (arg->a->size > 1 && i < size)
	{
		if (arg->a->tab[1] == piv && arg->a->tab[0] > arg->a->tab[1])
		{
			if (arg->a->tab[0] < arg->a->tab[arg->a->size - 1])
				move_check(arg, "sa", 1);
			else
				move_check(arg, "ra", 1);
			i++;
		}
		if (check_tab(arg->a->tab, arg->a->size) == 1
				&& (arg->a->tab[0] == piv || arg->a->size == 2))
			return (1);
		i = sort_a_five_next(piv, arg, i, size);
		i++;
	}
	return (0);
}

void			sort_five(t_ab *arg)
{
	int i;

	i = 0;
	while (check_valid(arg->a, arg->b) == -1)
	{
		while (arg->a->size > 1 && i == 0)
			i = sort_a_five(arg, 0, arg->a->size, get_pivot_five(arg->a));
		i = 0;
		while (arg->b->size > 0)
			sort_b_five(arg);
	}
}
