/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:09:11 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:09:12 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_space_float(t_arg *arg, int sign, int i)
{
	char	*str;

	i = ft_rec_c(arg->print, '0');
	if (ft_addflag(arg, SPACE) && sign == 0 && *arg->print != ' ')
	{
		if (arg->min_width == arg->print_size && ft_addflag(arg, ZERO)
				&& i >= 2)
			*arg->print = ' ';
		else if (arg->min_width == arg->print_size
				&& ft_addflag(arg, LEFT_JUST)
				&& arg->print[arg->print_size - 1] == ' ')
		{
			if (!(str = ft_strnew(arg->print_size)))
				return (0);
			ft_memset(str, ' ', arg->print_size);
			*str = ' ';
			ft_memcpy(str + 1, arg->print, arg->print_size - 1);
			free(arg->print);
			arg->print = str;
		}
		else
			arg->print = ft_strjoin_free(" ", arg->print, 2);
		arg->print_size = ft_strlen(arg->print);
	}
	return (1);
}
