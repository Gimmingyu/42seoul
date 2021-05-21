/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sharp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:08:34 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:08:35 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_sharp(t_arg *arg)
{
	arg->old_print = NULL;
	if (ft_addflag(arg, SHARP))
	{
		if (arg->arg_type == 'o')
			arg->old_print = "0";
		else if (arg->arg_type == 'x')
			arg->old_print = "0x";
		else if (arg->arg_type == 'X')
			arg->old_print = "0X";
		arg->old_print_size = ft_strlen(arg->old_print);
		arg->old_print_size = ft_strlen(arg->old_print);
	}
	else
		arg->old_print_size = 0;
	return (1);
}
