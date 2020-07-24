/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:00:23 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 07:05:45 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	get_plus(int num1, int num2)
{
	return (num1 + num2);
}

int	get_minus(int num1, int num2)
{
	return (num1 - num2);
}

int	get_multiple(int num1, int num2)
{
	return (num1 * num2);
}

int	get_divide(int num1, int num2)
{
	return (num1 / num2);
}

int	get_mod(int num1, int num2)
{
	return (num1 % num2);
}
