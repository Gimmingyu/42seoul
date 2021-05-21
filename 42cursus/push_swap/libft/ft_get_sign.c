/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:56:49 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:56:52 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_sign_size(char sign, t_arg *arg)
{
	char *str;

	if (!(str = ft_strnew(arg->print_size + 1)))
		return (0);
	*str = sign;
	ft_memcpy(str + 1, arg->print, arg->print_size);
	free(arg->print);
	arg->print = str;
	arg->print_size++;
	return (1);
}

static int	ft_sign_left(char sign, t_arg *arg)
{
	char *str;

	if (!(str = ft_strnew(arg->print_size)))
		return (0);
	*str = sign;
	ft_memcpy(str + 1, arg->print, arg->print_size);
	free(arg->print);
	arg->print = str;
	arg->print_size = !(ft_strchr(arg->print, ' ')) ?
		ft_strlen(arg->print) : arg->print_size;
	return (1);
}

int			ft_get_sign(t_arg *arg, int sign_neg)
{
	int		nb_space;
	char	sign;

	nb_space = 0;
	if (ft_addflag(arg, SIGN) || sign_neg)
	{
		sign = sign_neg ? '-' : '+';
		while (*(arg->print + nb_space) == ' ')
			nb_space++;
		if (arg->precision == arg->print_size)
			ft_sign_size(sign, arg);
		else if (arg->min_width == arg->print_size
				&& (ft_addflag(arg, LEFT_JUST)))
			ft_sign_left(sign, arg);
		else if (*(arg->print) == '0' && arg->print_size > 1)
			*(arg->print) = sign;
		else
		{
			if (nb_space != 0)
				*(arg->print + nb_space - 1) = sign;
			else
				ft_sign_size(sign, arg);
		}
	}
	return (1);
}
