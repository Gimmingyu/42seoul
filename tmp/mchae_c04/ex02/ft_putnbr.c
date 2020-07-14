/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:06:38 by mchae             #+#    #+#             */
/*   Updated: 2020/07/13 07:08:39 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		print(long long nb)
{
	char	put_num;

	if (nb >= 10)
	{
		print(nb / 10);
	}
	put_num = (char)(nb % 10) + 48;
	write(1, &put_num, 1);
}

void		ft_putnbr(int nb)
{
	long long long_nb;

	long_nb = (long long)nb;
	if (nb < 0)
	{
		long_nb *= -1;
		write(1, "-", 1);
	}
	print(long_nb);
}
