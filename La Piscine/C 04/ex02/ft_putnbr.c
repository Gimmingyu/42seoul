/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 20:45:31 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/16 02:26:38 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rev_putnbr(int n)
{
	char temp;

	temp = n % 10 + '0';
	if (n >= 10)
		rev_putnbr(n / 10);
	write(1, &temp, 1);
}

void	ft_putnbr(int nb)
{
	char temp;

	if (nb < 0)
	{
		write(1, "-", 1);
		temp = nb % 10 * (-1) + '0';
		nb /= -10;
		if (nb > 10)
			rev_putnbr(nb);
		write(1, &temp, 1);
	}
	else
		rev_putnbr(nb);
}
