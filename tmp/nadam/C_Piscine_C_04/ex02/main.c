/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:14:17 by jko               #+#    #+#             */
/*   Updated: 2020/01/28 10:28:00 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

int		main(void)
{
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(-2);
	write(1, "\n", 1);
	ft_putnbr(1);
	write(1, "\n", 1);
	ft_putnbr(11);
	write(1, "\n", 1);
	ft_putnbr(-11);
	write(1, "\n", 1);
	ft_putnbr(123456789);
	write(1, "\n", 1);
	ft_putnbr(-123456789);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	return (0);
}
