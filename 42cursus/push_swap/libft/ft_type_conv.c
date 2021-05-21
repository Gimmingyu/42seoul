/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:17:03 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:17:03 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_type_octal(va_list ap, t_arg *arg)
{
	return (ft_unsigned(ap, arg, 8));
}

int		ft_type_unsigned(va_list ap, t_arg *arg)
{
	return (ft_unsigned(ap, arg, 10));
}

int		ft_type_hexmin(va_list ap, t_arg *arg)
{
	int i;

	i = ft_type_hexmaj(ap, arg);
	ft_strlower(arg->print);
	return (i);
}

int		ft_type_hexmaj(va_list ap, t_arg *arg)
{
	return (ft_unsigned(ap, arg, 16));
}
