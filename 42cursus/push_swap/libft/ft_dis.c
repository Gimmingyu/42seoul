/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:54:50 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:54:51 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	ft_prefill(t_arg *arg, va_list ap)
{
	if (arg->min_width == -1)
		arg->min_width = va_arg(ap, int);
	if (arg->precision == -1)
		arg->precision = va_arg(ap, int);
	if (arg->precision < 0 && arg->precision != -2 && arg->arg_type == 'f')
		arg->precision = 0;
}

int				ft_dis(t_arg *arg, va_list ap)
{
	int (*type_ft)(va_list ap, t_arg *arg);

	ft_prefill(arg, ap);
	if (!(type_ft = g_ft_get_type(arg->arg_type)))
		return (-1);
	if (!(type_ft(ap, arg)))
		return (0);
	write(1, arg->print, arg->print_size);
	free(arg->print);
	return (arg->print_size);
}
