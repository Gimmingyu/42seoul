/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:31:56 by imgwang-yeo       #+#    #+#             */
/*   Updated: 2020/07/08 17:03:54 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		gethex(unsigned char n)
{
	if (n < 10)
	{
		return (n + 48);
	}
	return (n + 87);
}

void		printhex(unsigned char str)
{
	unsigned char ascii;

	write(1, "\\", 1);
	ascii = gethex(str / 16 % 16);
	write(1, &ascii, 1);
	ascii = gethex(str % 16);
	write(1, &ascii, 1);
}

void		ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 32 && *str <= 126))
		{
			printhex(*str);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
}
