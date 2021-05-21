/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:17:10 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:17:13 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_round(t_arg *arg, int i)
{
	i--;
	while (i != 0 && (arg->print[i] == '9' || arg->print[i] == '.'))
	{
		if (arg->print[i] != '.')
			arg->print[i] = '0';
		i--;
	}
	if (i == 0 && arg->print[i] == '9')
	{
		arg->print[i] = '0';
		if (!(arg->print = ft_strjoin_free("1", arg->print, 2)))
			return (0);
	}
	else
		arg->print[i] += 1;
	return (1);
}

int			ft_check_if_round(t_arg *arg, int i)
{
	if (arg->precision >= 1)
	{
		if ((arg->print[i - 1] - 48) % 2 == 0)
		{
			if (arg->precision == 1)
			{
				if (arg->print[arg->precision + i] >= '5' &&
						arg->print[arg->precision + i + 1] >= '5')
					return (1);
			}
			else
			{
				if (arg->print[arg->precision + i] >= '5')
					return (1);
			}
		}
		else if ((arg->print[i - 1] - 48) % 2 != 0)
		{
			if (arg->print[arg->precision + i] >= '5')
				return (1);
		}
	}
	else if (arg->precision == 0)
		return (0);
	return (0);
}

int			ft_check_round(t_arg *arg)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (arg->print[i] != '.')
		i++;
	if (ft_check_if_round(arg, i) == 1)
		ft_round(arg, i + arg->precision);
	i = 0;
	while (arg->print[i] != '.')
		i++;
	str = arg->precision == 1 ? ft_strsub(arg->print, 0, i) :
		ft_strsub(arg->print, 0, arg->precision + i);
	free(arg->print);
	arg->print = str;
	arg->print_size = ft_strlen(arg->print);
	return (1);
}

int			ft_sharpf(t_arg *arg)
{
	if (ft_addflag(arg, SHARP) && (arg->precision == 1 || arg->precision == 0))
	{
		if (!(arg->print = ft_strjoin_free(arg->print, ".", 1)))
			return (0);
		arg->print_size++;
	}
	return (1);
}

int			ft_type_float(va_list ap, t_arg *arg)
{
	char			*mantissa;
	t_floatbits		fl;

	if (ft_strequ("L", arg->len))
		fl.d = va_arg(ap, long double);
	else if (ft_strequ("l", arg->len))
		fl.d = va_arg(ap, double);
	else
		fl.d = va_arg(ap, double);
	mantissa = ft_bin_mant(fl.bits.m, 64);
	if ((fl.bits.expo > 32766 || fl.bits.expo < 0))
	{
		arg->print = ft_inf_nan(fl.bits.expo - 16383, mantissa, arg);
		if (ft_strcmp(arg->print, "inf") == 0)
		{
			ft_space_float(arg, fl.bits.sign, 0);
			ft_sign_float(arg, fl.bits.sign);
		}
		ft_width_inf_nan(arg, fl.bits.expo);
		free(mantissa);
	}
	else
		ft_fl_ok(arg, mantissa, &fl);
	arg->print_size = ft_strlen(arg->print);
	return (1);
}
