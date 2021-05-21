/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:18:38 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:18:39 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_width_f(t_arg *arg, int sign)
{
	char	*str;
	char	pad;
	int		i;

	if (ft_addflag(arg, SIGN) || sign == 1 || ft_addflag(arg, SPACE))
		i = 1;
	else
		i = 0;
	pad = ' ';
	pad = ft_addflag(arg, ZERO) ? '0' : ' ';
	if (arg->min_width > arg->print_size + i)
	{
		if (!(str = ft_strnew(arg->min_width)))
			return (0);
		ft_memset(str, pad, arg->min_width);
		if (ft_addflag(arg, LEFT_JUST))
			ft_memcpy(str, arg->print, arg->print_size);
		else
			ft_memcpy(str + arg->min_width - arg->print_size, arg->print,
					arg->print_size);
		free(arg->print);
		arg->print = str;
		arg->print_size = ft_strlen(arg->print);
	}
	return (1);
}
