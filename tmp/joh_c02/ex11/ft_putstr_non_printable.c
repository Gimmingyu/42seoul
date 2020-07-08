/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:44:02 by joh               #+#    #+#             */
/*   Updated: 2020/07/06 22:25:57 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

bool	ft_str_is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

void	ft_putstr_non_printable(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (ft_str_is_printable(str[index]))
		{
			ft_putchar(str[index]);
		}
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str[index] / 16]);
			ft_putchar("0123456789abcdef"[str[index] % 16]);
		}
		index++;
	}
}
