/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:58:58 by jipark            #+#    #+#             */
/*   Updated: 2020/02/05 15:41:37 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

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
