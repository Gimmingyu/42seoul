/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 09:56:11 by jipark            #+#    #+#             */
/*   Updated: 2020/02/07 09:58:05 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		get_number(char *str)
{
	int	result;
	int	count;

	count = 0;
	result = 0;
	while (str[count] != '\0' &&
	(str[count] == ' ' || (9 <= str[count] && str[count] <= 13)))
		count++;
	while (str[count] != '\0' && (str[count] == '-' || str[count] == '+'))
		count++;
	while (str[count] != '\0' && ('0' <= str[count] && str[count] <= '9'))
	{
		result = result * 10 + (str[count] - '0');
		count++;
	}
	return (result);
}

int		check_only_number(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
