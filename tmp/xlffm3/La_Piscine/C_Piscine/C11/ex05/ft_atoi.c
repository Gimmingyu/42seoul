/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 21:04:36 by jipark            #+#    #+#             */
/*   Updated: 2020/02/05 15:42:19 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_doop.h"

int	ft_atoi(char *str)
{
	int	result;
	int	count;
	int	is_minus;

	is_minus = 1;
	count = 0;
	result = 0;
	while (str[count] != '\0' &&
	(str[count] == ' ' || (9 <= str[count] && str[count] <= 13)))
		count++;
	while (str[count] != '\0' && (str[count] == '-' || str[count] == '+'))
	{
		if (str[count] == '-')
			is_minus *= -1;
		count++;
	}
	while (str[count] != '\0' && ('0' <= str[count] && str[count] <= '9'))
	{
		result = result * 10 + (str[count] - '0');
		count++;
	}
	return (result * is_minus);
}
