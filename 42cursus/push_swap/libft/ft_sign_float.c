/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sign_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:08:41 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:08:42 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_sign_size(t_arg *arg, int sign)
{
	char *str;

	if (!(str = ft_strnew(arg->print_size)))
		return (0);
	ft_memset(str, ' ', arg->print_size);
	*str = sign == 1 ? '-' : '+';
	ft_memcpy(str + 1, arg->print, arg->print_size - 1);
	free(arg->print);
	arg->print = str;
	return (1);
}

int			ft_sign_float(t_arg *arg, int sign)
{
	int i;
	int l;

	i = ft_rec_c(arg->print, ' ');
	l = ft_rec_c(arg->print, '0');
	if (ft_addflag(arg, SIGN) || sign == 1)
	{
		if ((*arg->print == '0' && ft_addflag(arg, ZERO) && l >= 2) || i == 1)
			*arg->print = sign == 1 ? '-' : '+';
		else if (i > 1 || (ft_addflag(arg, LEFT_JUST)
					&& arg->print[arg->print_size - 1] == ' '))
		{
			if (i > 1)
				*(arg->print + i - 1) = sign == 1 ? '-' : '+';
			else
				ft_sign_size(arg, sign);
		}
		else
			arg->print = sign == 1 ? ft_strjoin_free("-", arg->print, 2)
				: ft_strjoin_free("+", arg->print, 2);
		if (!(arg->print))
			return (0);
		arg->print_size = ft_strlen(arg->print);
	}
	return (1);
}
