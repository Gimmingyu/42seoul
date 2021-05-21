/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:08:56 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:08:57 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	int	ft_space_d_zero(t_arg *arg)
{
	char *str;

	if (!(str = ft_strnew(arg->print_size)))
		return (0);
	*str = ' ';
	if (arg->print[arg->print_size - 1] == ' ')
		ft_memcpy(str + 1, arg->print, arg->print_size - 1);
	else
		ft_memcpy(str + 1, arg->print, arg->print_size);
	free(arg->print);
	arg->print = str;
	return (1);
}

static	int	ft_space_d_size(t_arg *arg)
{
	char *str;

	if (!(str = ft_strnew(arg->print_size + 1)))
		return (0);
	*str = ' ';
	ft_memcpy(str + 1, arg->print, arg->print_size);
	free(arg->print);
	arg->print = str;
	return (1);
}

int			ft_space_d(t_arg *arg, int sign_neg)
{
	if (ft_addflag(arg, SPACE) && !sign_neg)
	{
		if (ft_addflag(arg, SPACE) && !sign_neg && ft_isdigit(*(arg->print))
				&& arg->min_width != arg->print_size)
			ft_space_d_size(arg);
		else if (ft_addflag(arg, SPACE) && !sign_neg
				&& ft_isdigit(*(arg->print))
				&& arg->min_width == arg->print_size
				&& ft_addflag(arg, ZERO) == 0)
			ft_space_d_zero(arg);
		else if (ft_addflag(arg, SPACE) && !sign_neg
				&& ft_isdigit(*(arg->print))
				&& arg->min_width == arg->print_size
				&& ft_addflag(arg, ZERO) && *arg->print == '0')
			*(arg->print) = ' ';
		else if (*arg->print != ' ' && arg->print[arg->print_size - 1] != ' ')
			if (!(arg->print = ft_strjoin_free(" ", arg->print, 2)))
				return (0);
		arg->print_size = ft_strlen(arg->print);
	}
	return (1);
}
