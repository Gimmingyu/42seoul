/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:16:53 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:16:54 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int		ft_width(t_arg *arg)
{
	char *str_new;

	if (arg->print_size >= arg->min_width)
		return (1);
	if (!(str_new = ft_strnew(arg->min_width)))
		return (0);
	if (ft_addflag(arg, LEFT_JUST))
	{
		ft_memcpy(str_new, arg->print, arg->print_size);
		ft_memset(str_new + arg->print_size, ' ',
				arg->min_width - arg->print_size);
	}
	else
	{
		ft_memset(str_new, ' ', arg->min_width - arg->print_size);
		ft_memcpy(str_new + (arg->min_width - arg->print_size),
				arg->print, arg->print_size);
	}
	free(arg->print);
	arg->print = str_new;
	arg->print_size = arg->min_width;
	return (1);
}

int				ft_type_char(va_list ap, t_arg *arg)
{
	if (!(arg->print = ft_strnew(1)))
		return (0);
	*(arg->print) = va_arg(ap, int);
	arg->print_size = 1;
	return (ft_width(arg));
}
