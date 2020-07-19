/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:33:16 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/13 22:07:46 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"
#include "unistd.h"

void	op_add(int n1, int n2)
{
	ft_putnbr(n1 + n2);
	return ;
}

void	op_sub(int n1, int n2)
{
	ft_putnbr(n1 - n2);
	return ;
}

void	op_div(int n1, int n2)
{
	if (n2 == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return ;
	}
	ft_putnbr(n1 / n2);
	return ;
}

void	op_mul(int n1, int n2)
{
	ft_putnbr(n1 * n2);
	return ;
}

void	op_mod(int n1, int n2)
{
	if (n2 == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return ;
	}
	ft_putnbr(n1 % n2);
	return ;
}
