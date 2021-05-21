/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:29:44 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/17 18:29:46 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stack_nd_next(t_stack *tab_tmp, t_ab *arg, int c_ra, int pos)
{
	if (tab_tmp->size > 1 && (check_tab(arg->a->tab, arg->a->size) == -1))
		add_pivot(arg->sb, tab_tmp->tab[pos]);
	if (c_ra != arg->a->size)
	{
		if (c_ra < arg->a->size || c_ra <= 1)
		{
			while (c_ra != 0)
			{
				move_check(arg, "rra", 1);
				if (arg->a->tab[0] > arg->a->tab[1])
					move_check(arg, "sa", 1);
				c_ra--;
			}
		}
	}
	free_stack(tab_tmp);
	if (!(tab_tmp = copy_stack(arg->a, arg->sa)))
		return ;
	if (check_tab(tab_tmp->tab, tab_tmp->size) == 1 && arg->sa->size > 0)
		arg->sa->size = arg->sa->size - 1;
	free_stack(tab_tmp);
}

void	sort_stack_fst_next(t_stack *tab_tmp, t_ab *arg, int c_rb, int pos)
{
	if (tab_tmp->size >= 1 && (check_tab(arg->a->tab, arg->a->size) == -1))
		add_pivot(arg->sa, tab_tmp->tab[pos]);
	if (arg->sb->size > 0 && (check_tab(arg->a->tab, arg->a->size) == 1
				|| tab_tmp->size <= 3))
		arg->sb->size = arg->sb->size - 1;
	if (c_rb != arg->b->size)
	{
		if (c_rb < (arg->b->size / 2) || c_rb == 1)
		{
			while (c_rb-- != 0)
			{
				move_check(arg, "rrb", 1);
				if (arg->b->tab[0] < arg->b->tab[1])
					move_check(arg, "sb", 1);
			}
		}
		else
		{
			while (arg->b->size - c_rb != 0)
			{
				move_check(arg, "rb", 1);
				c_rb++;
			}
		}
	}
}
