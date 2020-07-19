/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:04:32 by jipark            #+#    #+#             */
/*   Updated: 2020/01/23 12:05:43 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char count;
	char number;

	count = 0;
	number = '0';
	while (count < 10)
	{
		write(1, &number, 1);
		count++;
		number++;
	}
}
