/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 19:43:48 by jko               #+#    #+#             */
/*   Updated: 2020/01/23 17:56:42 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_zero(void)
{
	char c;

	c = '0';
	write(1, &c, 1);
}

void	print_negative(int *nb, int *nums, int *index)
{
	char c;

	c = '-';
	write(1, &c, 1);
	nums[(*index)++] = (*nb % 10) * -1;
	*nb /= -10;
}

void	print_num(int *nums, int *index)
{
	char c;

	while (*index >= 0)
	{
		c = nums[(*index)--] + 48;
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	int		nums[10];
	int		index;

	index = 0;
	if (nb == 0)
	{
		print_zero();
		return ;
	}
	if (nb < 0)
		print_negative(&nb, nums, &index);
	while (nb / 10 > 0)
	{
		nums[index++] = nb % 10;
		nb /= 10;
	}
	if (nb != 0)
		nums[index] = nb;
	else
		index--;
	print_num(nums, &index);
}
