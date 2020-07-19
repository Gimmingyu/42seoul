/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:55:48 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/28 01:54:37 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	print_putnbr_base(long nbr, char *base, int len)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		print_putnbr_base(nbr * -1, base, len);
		return ;
	}
	else if (nbr > len - 1)
		print_putnbr_base(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}

int		checker(char *base, unsigned int len)
{
	unsigned int i;
	unsigned int j;

	if (len <= 1)
		return (0);
	i = 0 - 1;
	while (++i < len - 1)
	{
		j = i + 1 - 1;
		while (++j < len)
			if (base[i] == base[j])
				return (0);
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int len;

	len = 0;
	while (base[len])
	{
		if (base[len] == '+' || base[len] == '-')
			return ;
		len++;
	}
	if (!checker(base, len))
		return ;
	print_putnbr_base((long)nbr, base, len);
}
