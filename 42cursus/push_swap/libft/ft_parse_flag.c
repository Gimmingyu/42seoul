/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:02:21 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:02:22 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_addflag(t_arg *arg, int flag)
{
	return (arg->flags & flag);
}

int				ft_parse_flag(const char *str, t_arg *arg)
{
	int i;

	i = 0;
	while ((*(str + i)) == '-' || (*(str + i)) == '+' || (*(str + i) == '#')
			|| (*(str + i) == '0') || (*(str + i)) == ' ')
	{
		if (*(str + i) == '-')
			arg->flags |= LEFT_JUST;
		else if (*(str + i) == '+')
			arg->flags |= SIGN;
		else if (*(str + i) == '#')
			arg->flags |= SHARP;
		else if (*(str + i) == '0')
			arg->flags |= ZERO;
		else if (*(str + i) == ' ')
			arg->flags |= SPACE;
		i++;
	}
	return (i);
}
