/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:11:55 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/17 17:11:56 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	little_sort(t_stack *tmp, t_ab *arg)
{
	if (tmp->size >= 4)
	{
		sort_five(arg);
		return ;
	}
	if (tmp->size <= 1)
		return ;
	if (tmp->size == 2)
	{
		if (tmp->tab[0] > tmp->tab[1])
			move_check(arg, "ra", 1);
		free_stack(tmp);
		return ;
	}
	free_stack(tmp);
	while (check_tab(arg->a->tab, arg->a->size) == -1)
	{
		if (!(tmp = copy_stack(arg->a, arg->sa)))
			return ;
		if (tmp->tab[0] > tmp->tab[1])
			move_check(arg, "sa", 1);
		if (tmp->tab[1] > tmp->tab[2])
			move_check(arg, "rra", 1);
		free_stack(tmp);
	}
}

void	sort_stack_fst(int c, t_ab *arg, t_stack *tab_tmp, int pos)
{
	int c_rb;

	c_rb = 0;
	if (!(tab_tmp = copy_stack(arg->b, arg->sb)))
		return ;
	pos = get_pivot(tab_tmp);
	while (++c < tab_tmp->size)
	{
		if (c > pos && check_tab(arg->a->tab, arg->a->size - 1) == -1
				&& check_pivot_tab_dn(arg->b, tab_tmp->tab[pos]) == 1)
			break ;
		arg->a->tab[0] > arg->a->tab[1] ? move_check(arg, "sa", 1) : 0;
		if (tab_tmp->tab[c] >= tab_tmp->tab[pos])
		{
			move_check(arg, "pa", 1);
			if (arg->a->size > 2 && c == pos)
				move_check(arg, "ra", 1);
		}
		else
			c_rb = c_rb + move_check(arg, "rb", 1);
	}
	sort_stack_fst_next(tab_tmp, arg, c_rb, pos);
	if (arg->a->size > 2 && c > pos)
		move_check(arg, "rra", 1);
	free_stack(tab_tmp);
}

void	sort_stack_nd(int c, t_ab *arg, t_stack *tab_tmp, int pos)
{
	int c_ra;

	if (!(tab_tmp = copy_stack(arg->a, arg->sa)))
		return ;
	pos = get_med(tab_tmp, -1, -1, 0);
	c_ra = 0;
	while (++c < tab_tmp->size
			&& (check_tab(arg->a->tab, arg->a->size) == -1))
	{
		if (c > pos && check_pivot_tab_up(arg->a, tab_tmp->tab[pos]) == 1)
			break ;
		if (arg->b->size > 1 && arg->b->tab[0] < arg->b->tab[1])
			move_check(arg, "sb", 1);
		if (tab_tmp->tab[c] <= tab_tmp->tab[pos])
		{
			arg->a->size > 1 ? move_check(arg, "pb", 1) : 0;
			if (arg->a->size > 1 && arg->b->size > 1 && c == pos)
				move_check(arg, "rb", 1);
		}
		else
			c_ra = c_ra + move_check(arg, "ra", 1);
	}
	if (arg->b->size > 1 && c > pos)
		move_check(arg, "rrb", 1);
	sort_stack_nd_next(tab_tmp, arg, c_ra, pos);
}

void	start_sort(int c, t_ab *arg, t_stack *tab_tmp, int pos)
{
	int i;

	if (!(tab_tmp = copy_stack(arg->a, arg->sa)))
		return ;
	if (arg->size <= 5)
		little_sort(tab_tmp, arg);
	pos = get_med(arg->a, -1, -1, 0);
	i = arg->a->size;
	while (arg->size > 5 && ++c < i && arg->a->size > 1)
	{
		if (c <= pos && arg->b->size > 1
					&& arg->b->tab[0] < arg->b->tab[1])
			move_check(arg, "sb", 1);
		if (tab_tmp->tab[c] <= tab_tmp->tab[pos])
		{
			move_check(arg, "pb", 1);
			if (c > pos)
				move_check(arg, "sb", 1);
		}
		else if (arg->a->size > 1)
			move_check(arg, "ra", 1);
	}
	add_pivot(arg->sb, tab_tmp->tab[pos]);
	if (arg->size > 3)
		free_stack(tab_tmp);
}

void	sort(t_ab *arg, int use)
{
	t_stack	*tab_tmp;

	tab_tmp = NULL;
	if (use == 0)
		start_sort(-1, arg, tab_tmp, 0);
	if (use == 1)
		sort_stack_fst(-1, arg, tab_tmp, 0);
	if (use == 2)
		sort_stack_nd(-1, arg, tab_tmp, 0);
}
