/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:45:31 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/16 02:05:43 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	recursive(int n)
{
	if (n > 9)
	{
		recursive(n / 10);
		recursive(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putnbr(int nb)
{
	unsigned int num;

	num = (unsigned int)nb;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	recursive(num);
}
