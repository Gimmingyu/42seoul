/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zero_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:54:43 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:54:44 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_zero_d(t_arg *arg)
{
	if (arg->flags == 0)
		return (ft_spec_zero_d(arg));
	else
		return (ft_spec_zero_d_flag(arg));
}
