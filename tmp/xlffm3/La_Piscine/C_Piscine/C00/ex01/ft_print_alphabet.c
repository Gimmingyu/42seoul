/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 11:58:30 by jipark            #+#    #+#             */
/*   Updated: 2020/01/23 12:00:53 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char count;
	char alphabet;

	count = 0;
	alphabet = 'a';
	while (count < 26)
	{
		write(1, &alphabet, 1);
		alphabet++;
		count++;
	}
}
