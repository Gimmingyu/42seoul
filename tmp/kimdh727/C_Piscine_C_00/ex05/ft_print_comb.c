/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:22:01 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/23 12:28:49 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char first_num;
	char second_num;
	char third_num;

	third_num = '0' - 1;
	while (++third_num < '8')
	{
		second_num = third_num;
		while (++second_num < '9')
		{
			first_num = second_num;
			while (++first_num <= '9')
			{
				write(1, &third_num, 1);
				write(1, &second_num, 1);
				write(1, &first_num, 1);
				if (third_num != '7')
					write(1, ", ", 2);
			}
		}
	}
}
