/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:50:37 by jko               #+#    #+#             */
/*   Updated: 2020/01/23 17:03:25 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int num)
{
	char n[2];

	n[0] = num / 10 + 48;
	n[1] = num % 10 + 48;
	write(1, &n, 2);
}

void	ft_print_comb2(void)
{
	int		nums[2];
	char	chars[2];

	nums[0] = 0;
	chars[0] = ',';
	chars[1] = ' ';
	while (nums[0] <= 98)
	{
		nums[1] = nums[0] + 1;
		while (nums[1] <= 99)
		{
			print(nums[0]);
			write(1, &chars[1], 1);
			print(nums[1]);
			if (!(nums[0] == 98 && nums[1] == 99))
			{
				write(1, &chars, 2);
			}
			nums[1]++;
		}
		nums[0]++;
	}
}
