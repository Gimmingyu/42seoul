/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:07:48 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:07:48 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 0 && n != -2147483648)
	{
		n = -n;
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(2);
		ft_putnbr(147483648);
	}
}
