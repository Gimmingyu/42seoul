/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:02:41 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:02:42 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse_precision(const char *str, t_arg *arg)
{
	int i;

	i = 1;
	if (*(str) != '.')
		return (0);
	if (*(str + i) == '*')
	{
		arg->precision = -1;
		while (*(str + i) == '*')
			i++;
		return (i);
	}
	else if (*(str + i) >= '0' && *(str + i) <= '9')
	{
		arg->precision = ft_atoi(str + i);
		while (*(str + i) >= '0' && *(str + i) <= '9')
			i++;
		if (arg->precision == 0)
			arg->precision = -2;
	}
	else
		arg->precision = -2;
	return (i);
}
