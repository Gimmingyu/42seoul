/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:38:25 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 19:37:09 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	get_hex(int n)
{
	if (n < 10)
		return (n + 48);
	return (n + 87);
}

void	print_non_printable(unsigned char c)
{
	unsigned char asci;

	write(1, "\\", 1);
	asci = get_hex(c / 16 % 16);
	write(1, &asci, 1);
	asci = get_hex(c % 16);
	write(1, &asci, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] >= 32 && str[index] <= 126)
			write(1, &str[index], 1);
		else
			print_non_printable(str[index]);
		index++;
	}
}
