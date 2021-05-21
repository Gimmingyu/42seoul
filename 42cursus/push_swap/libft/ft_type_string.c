/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:17:48 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:17:49 by kyekim           ###   ########.fr       */
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

static	void	ft_precision(t_arg *arg)
{
	if (arg->precision == -2)
		arg->print_size = 0;
	else if (arg->precision < arg->print_size && arg->precision != 0)
		arg->print_size = arg->precision;
}

int				ft_type_string(va_list ap, t_arg *arg)
{
	char *tmp;

	tmp = va_arg(ap, char *);
	if (tmp == NULL)
		tmp = "(null)";
	if (!(arg->print = ft_strdup(tmp)))
		return (0);
	arg->print_size = ft_strlen(arg->print);
	ft_precision(arg);
	return (ft_width(arg));
}
