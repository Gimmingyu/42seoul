/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:02:08 by jipark            #+#    #+#             */
/*   Updated: 2020/01/23 12:03:43 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char count;
	char alphabet;

	count = 0;
	alphabet = 'z';
	while (count < 26)
	{
		write(1, &alphabet, 1);
		alphabet--;
		count++;
	}
}
