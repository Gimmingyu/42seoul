/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:39:57 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/27 11:39:58 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

void	print_hex(unsigned long data, int digit, int n)
{
	unsigned char print;

	if (n < digit - 1)
		print_hex(data >> 4, digit, n + 1);
	print = (data & 0xf);
	if (print < 10)
		print += '0';
	else
		print += ('a' - 10);
	write(1, &print, 1);
}

void	print_char_to_hex(char c)
{
	write(1, "\\", 1);
	print_hex((unsigned long)c, 2, 0);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		if (is_printable(str[i]))
			write(1, &str[i], 1);
		else
			print_char_to_hex(str[i]);
		i++;
	}
}
