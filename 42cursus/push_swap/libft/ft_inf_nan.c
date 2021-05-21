/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inf_nan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:57:06 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:57:07 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_width_inf_nan(t_arg *arg, int sign)
{
	char	*str;
	char	pad;
	int		i;

	if (ft_addflag(arg, SIGN) || sign == 1 || ft_addflag(arg, SPACE))
		i = 1;
	else
		i = 0;
	pad = ' ';
	if (arg->min_width >= arg->print_size + i)
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

char	*ft_inf_nan(unsigned int expo, char *mantissa, t_arg *arg)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (mantissa[i])
	{
		if (mantissa[i] == '1')
			j++;
		i++;
	}
	if (expo > 16383 && j > 1)
	{
		arg->print_size = 3;
		return (ft_strdup("nan"));
	}
	else
	{
		arg->print_size = 3;
		return (ft_strdup("inf"));
	}
}
