/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:24:54 by jipark            #+#    #+#             */
/*   Updated: 2020/01/28 10:57:25 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_nbr(long long tmp)
{
	char txt;

	if (0 <= tmp && tmp < 10)
	{
		txt = tmp + '0';
		write(1, &txt, 1);
	}
	else
	{
		print_nbr(tmp / 10);
		txt = (tmp % 10) + '0';
		write(1, &txt, 1);
	}
}

void	ft_putnbr(int nb)
{
	long long tmp;

	tmp = nb;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp *= -1;
	}
	print_nbr(tmp);
}
