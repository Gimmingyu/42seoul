/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 02:05:52 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/16 02:06:43 by kyekim           ###   ########.fr       */
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
