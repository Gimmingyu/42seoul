/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:29:52 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/23 12:32:33 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_two_digit_num(int n)
{
	char c;

	if (n < 10)
	{
		write(1, "0", 1);
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		c = n / 10 + 48;
		write(1, &c, 1);
		c = n % 10 + 48;
		write(1, &c, 1);
	}
}

void	ft_print_comb2(void)
{
	int first_num;
	int second_num;

	first_num = 0 - 1;
	while (++first_num <= 98)
	{
		second_num = first_num;
		while (++second_num <= 99)
		{
			print_two_digit_num(first_num);
			write(1, " ", 1);
			print_two_digit_num(second_num);
			if (first_num != 98 || second_num != 99)
				write(1, ", ", 2);
		}
	}
}
