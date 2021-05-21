/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:17:20 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:17:21 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_precision(t_arg *arg)
{
	int		nb_digit;
	int		i;
	char	*str;

	nb_digit = 0;
	i = 0;
	while (*(arg->print + i) != '\0')
	{
		if (ft_isdigit(*(arg->print + i)))
			nb_digit++;
		i++;
	}
	if (nb_digit < arg->precision)
	{
		if (!(str = ft_strnew(arg->precision)))
			return (0);
		ft_memset(str, '0', arg->precision);
		ft_memcpy(str + (arg->precision - arg->print_size),
				arg->print, arg->print_size);
		free(arg->print);
		arg->print = str;
		arg->print_size = arg->precision;
	}
	return (1);
}

static int	ft_width(t_arg *arg, int sign_neg)
{
	char pad;
	char *str;

	sign_neg = sign_neg + 0;
	if (arg->precision != 0)
		pad = ' ';
	else
		pad = ft_addflag(arg, ZERO) ? '0' : ' ';
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

int			ft_spec_zero_d(t_arg *arg)
{
	char	*str;
	int		i;

	i = ft_addflag(arg, SPACE) || ft_addflag(arg, ZERO) ? 1 : 0;
	if (arg->min_width)
	{
		if (!(str = ft_strnew(arg->min_width)))
			return (0);
	}
	else
	{
		if (!(str = ft_strnew(i)))
			return (0);
	}
	arg->min_width ? ft_memset(str, ' ', arg->min_width) :
		ft_memset(str, ' ', i);
	free(arg->print);
	arg->print = str;
	arg->print_size = ft_strlen(arg->print);
	return (1);
}

int			ft_spec_zero_d_flag(t_arg *arg)
{
	char *str;

	str = NULL;
	if (arg->min_width > 0)
	{
		if (!(str = ft_strnew(arg->min_width)))
			return (0);
		ft_memset(str, ' ', arg->min_width);
	}
	else
	{
		if (!(str = ft_strnew(1)))
			return (0);
		ft_memset(str, ' ', 1);
	}
	if (ft_addflag(arg, SIGN))
		*(str + ft_strlen(str) - 1) = '+';
	else if (ft_addflag(arg, SPACE))
		*(str) = ' ';
	else if (ft_strlen(str) != (size_t)arg->min_width)
		*(str) = '\0';
	free(arg->print);
	arg->print = str;
	arg->print_size = ft_strlen(arg->print);
	return (1);
}

int			ft_type_int(va_list ap, t_arg *arg)
{
	int		sign_neg;
	char	*str;

	if (ft_strequ("l", arg->len))
		arg->print = ft_ltoa_base(va_arg(ap, long), 10);
	else if (ft_strequ("ll", arg->len))
		arg->print = ft_lltoa_base(va_arg(ap, long long), 10);
	else if (ft_strequ("h", arg->len))
		arg->print = ft_itoa_base((short)va_arg(ap, int), 10);
	else if (ft_strequ("hh", arg->len))
		arg->print = ft_itoa((signed char)va_arg(ap, int));
	else
		arg->print = ft_itoa(va_arg(ap, int));
	sign_neg = *(arg->print) == '-';
	str = ft_strsub(arg->print, sign_neg, ft_strlen(arg->print));
	free(arg->print);
	arg->print = str;
	arg->print_size = ft_strlen(arg->print);
	if (ft_strncmp(arg->print, "0", 2) == 0 && arg->precision == -2)
		return (ft_check_zero_d(arg));
	else
		return (ft_precision(arg) && ft_width(arg, sign_neg)
				&& ft_get_sign(arg, sign_neg) && ft_space_d(arg, sign_neg));
}
