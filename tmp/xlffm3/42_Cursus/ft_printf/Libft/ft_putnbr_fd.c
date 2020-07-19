/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 23:43:05 by jipark            #+#    #+#             */
/*   Updated: 2020/04/06 12:28:44 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_nbr_to_file(unsigned int tmp, int fd)
{
	char c;

	if (tmp >= 10)
		write_nbr_to_file(tmp / 10, fd);
	c = (tmp % 10) + '0';
	ft_putchar_fd(c, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int tmp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = n * -1;
	}
	else
		tmp = n;
	write_nbr_to_file(tmp, fd);
}
