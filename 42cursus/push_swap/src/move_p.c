/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:40:25 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/17 14:40:26 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int		move_p(t_stack *fi, t_stack *se)
{
	int i;

	i = se->size;
	if (fi->size > 0)
	{
		se->size += 1;
		while (i > 0)
		{
			se->tab[i] = se->tab[i - 1];
			i--;
		}
		se->tab[0] = fi->tab[0];
		i = 0;
		while (i + 1 < fi->size)
		{
			fi->tab[i] = fi->tab[i + 1];
			i++;
		}
		fi->size = fi->size - 1;
	}
	return (1);
}

int				move_pb(t_stack *a, t_stack *b)
{
	move_p(a, b);
	return (1);
}

int				move_pa(t_stack *a, t_stack *b)
{
	move_p(b, a);
	return (1);
}
