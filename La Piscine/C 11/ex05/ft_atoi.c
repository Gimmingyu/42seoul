/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 01:27:19 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 07:12:22 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	ft_atoi(char *str)
{
	int	res;
	int	cnt;
	int	sign;

	sign = 1;
	cnt = 0;
	res = 0;
	while (str[cnt] != '\0' &&
	(str[cnt] == ' ' || (9 <= str[cnt] && str[cnt] <= 13)))
		cnt++;
	while (str[cnt] != '\0' && (str[cnt] == '-' || str[cnt] == '+'))
	{
		if (str[cnt] == '-')
			sign *= -1;
		cnt++;
	}
	while (str[cnt] != '\0' && ('0' <= str[cnt] && str[cnt] <= '9'))
	{
		res = res * 10 + (str[cnt] - '0');
		cnt++;
	}
	return (res * sign);
}
