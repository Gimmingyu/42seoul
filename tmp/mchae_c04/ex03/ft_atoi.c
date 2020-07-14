/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:07:46 by mchae             #+#    #+#             */
/*   Updated: 2020/07/09 15:49:02 by mchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*is_space(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
	{
		str++;
	}
	return (str);
}

int		ft_atoi(char *str)
{
	int minus;
	int	i;

	i = 0;
	minus = 0;
	str = is_space(str);
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i *= 10;
		i += (int)*str - 48;
		str++;
	}
	if (minus % 2 == 1)
		return (-i);
	else
		return (i);
}
