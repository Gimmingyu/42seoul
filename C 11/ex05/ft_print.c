/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 07:12:01 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 07:14:05 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_putnbr(int res)
{
	long long	tmp;
	char		c;

	if (res < 0)
	{
		write(1, "-", 1);
		tmp = ((long long)res) * -1;
	}
	else
		tmp = res;
	if (tmp >= 10)
		ft_putnbr(tmp / 10);
	c = tmp % 10 + '0';
	write(1, &c, 1);
}

void	print_content(int num1, int num2, char operator)
{
	int res;

	res = 0;
	if (operator == '+')
		res = g_arr[0](num1, num2);
	else if (operator == '-')
		res = g_arr[1](num1, num2);
	else if (operator == '*')
		res = g_arr[2](num1, num2);
	else if (operator == '/')
		res = g_arr[3](num1, num2);
	else if (operator == '%')
		res = g_arr[4](num1, num2);
	ft_putnbr(res);
}
