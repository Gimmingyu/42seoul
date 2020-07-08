/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 22:45:39 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/08 14:34:49 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_str_to_hex(unsigned char *str)
{
	char tmp[3];

	tmp[0] = '\\';
	tmp[1] = *str / 16;
	tmp[2] = *str % 16;
	if (tmp[1] < 10)
		tmp[1] = tmp[1] + '0';
	else
		tmp[1] = tmp[1] + 'a' - 10;
	if (tmp[2] < 10)
		tmp[2] = tmp[2] + '0';
	else
		tmp[2] = tmp[2] + 'a' - 10;
	write(1, tmp, 3);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (32 <= *str && *str < 127)
			write(1, str, 1);
		else
		{
			ft_print_str_to_hex((unsigned char *)str);
		}
		str++;
	}
}
