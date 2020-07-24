/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:12:59 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/13 12:13:01 by kyekim           ###   ########.fr       */
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
