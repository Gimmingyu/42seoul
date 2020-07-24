/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 12:53:34 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/21 14:20:13 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_get_num(char *str)
{
	int		res;
	int		cnt;

	cnt = 0;
	res = 0;
	while (str[cnt] != '\0' &&
	(str[cnt] == ' ' || (str[cnt] >= 9 && str[cnt] <= 13)))
		cnt++;
	while (str[cnt] != '\0' && (str[cnt] == '-' || str[cnt] == '+'))
		cnt++;
	while (str[cnt] != '\0' && (str[cnt] >= '0' && str[cnt] <= '9'))
	{
		res = res * 10 + (str[cnt] - '0');
		cnt++;
	}
	return (res);
}

int		ft_check_only_num(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
