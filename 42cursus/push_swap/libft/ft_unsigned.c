/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:18:33 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:18:33 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_precision(t_arg *arg)
{
	char	*str;
	int		i;
	int		nb_digit;

	str = NULL;
	nb_digit = 0;
	i = 0;
	while (*(arg->print + i) != '\0')
	{
		if (ft_isalnum(*(arg->print + i)))
			nb_digit++;
		i++;
	}
	if (nb_digit < arg->precision)
	{
		if (!(str = ft_strnew(arg->precision + 1)))
			return (0);
		ft_memset(str, '0', arg->precision);
		ft_memcpy(str + (arg->precision - arg->print_size),
				arg->print, arg->print_size);
		free(arg->print);
		arg->print = str;
		arg->print_size = ft_strlen(arg->print);
	}
	return (1);
}

static int	ft_width(t_arg *arg)
{
	char *str;
	char pad;

	pad = ft_addflag(arg, ZERO) ? '0' : ' ';
	pad = arg->precision != 0 ? ' ' : pad;
	if (arg->print_size < arg->min_width)
	{
		if (!(str = ft_strnew(arg->min_width)))
			return (0);
		ft_memset(str, pad, arg->min_width);
		if (ft_addflag(arg, LEFT_JUST))
			ft_memcpy(str, arg->print, arg->print_size);
		else
			ft_memcpy(str + (arg->min_width - arg->print_size),
					arg->print, arg->print_size);
		free(arg->print);
		arg->print = str;
		arg->print_size = ft_strlen(arg->print);
	}
	return (1);
}

int			ft_unsigned(va_list ap, t_arg *arg, int base)
{
	arg->old_print = NULL;
	if (ft_strequ("l", arg->len))
		arg->print = ft_ulitoa_base(va_arg(ap, unsigned long), base);
	else if (ft_strequ("ll", arg->len))
		arg->print = ft_ullitoa_base(va_arg(ap, unsigned long long), base);
	else if (ft_strequ("h", arg->len))
		arg->print = ft_uitoa_base((unsigned short)va_arg(ap, unsigned int),
				base);
	else if (ft_strequ("hh", arg->len))
		arg->print = ft_uitoa_base((unsigned char)va_arg(ap, unsigned int),
				base);
	else
		arg->print = ft_ulitoa_base(va_arg(ap, unsigned int), base);
	arg->print_size = ft_strlen(arg->print);
	if (ft_strncmp(arg->print, "0", 2) == 0 && arg->precision == -2)
		return (ft_spec_zero_u(arg));
	else if (ft_strcmp(arg->print, "0") == 0)
		return (ft_precision(arg) && ft_width(arg));
	else
		return (ft_sharp(arg) && ft_precision(arg) && ft_width(arg)
				&& ft_sp_u(arg));
}
