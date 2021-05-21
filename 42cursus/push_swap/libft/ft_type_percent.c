/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:17:28 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:17:29 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_type_percent(va_list ap, t_arg *arg)
{
	int i;

	i = 0;
	(void)ap;
	arg->print_size = arg->min_width > 0 ? arg->min_width : 1;
	if (!(arg->print = malloc(arg->print_size)))
		return (-1);
	ft_memset(arg->print, ' ', arg->print_size);
	*(arg->print + (ft_addflag(arg, LEFT_JUST) ? 0 :
				arg->print_size - 1)) = '%';
	while (ft_addflag(arg, ZERO) && *(arg->print + i) == ' ')
		*(arg->print + i++) = '0';
	return (1);
}
