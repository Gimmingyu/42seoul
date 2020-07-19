/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:03:22 by jipark            #+#    #+#             */
/*   Updated: 2020/01/26 11:48:26 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hexademical(unsigned char str)
{
	unsigned char tmp;

	if (10 <= str && str < 16)
	{
		tmp = 'a' + ((str % 16) - 10);
		write(1, &tmp, 1);
	}
	else if (str < 10)
	{
		tmp = str + 48;
		write(1, &tmp, 1);
	}
	else
	{
		print_hexademical(str / 16);
		if (str % 16 >= 10)
			tmp = 'a' + ((str % 16) - 10);
		else
			tmp = (str % 16) + 48;
		write(1, &tmp, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] >= 127)
		{
			write(1, "\\", 1);
			if (0 < str[i] && str[i] < 16)
				write(1, "0", 1);
			print_hexademical((unsigned char)str[i]);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
