/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:08:30 by jipark            #+#    #+#             */
/*   Updated: 2020/01/23 12:09:44 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	char first_num;
	char middle_num;
	char last_num;

	first_num = '0' - 1;
	while (++first_num <= '7')
	{
		middle_num = first_num + 1;
		while (middle_num <= '9')
		{
			last_num = middle_num + 1;
			while (last_num <= '9')
			{
				write(1, &first_num, 1);
				write(1, &middle_num, 1);
				write(1, &last_num, 1);
				if (first_num != '7' || middle_num != '8' || last_num != '9')
				{
					write(1, ", ", 2);
				}
				last_num++;
			}
			middle_num++;
		}
	}
}
