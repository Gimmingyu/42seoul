/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 11:42:38 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:50:59 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' ||
			*str == '\r' || *str == ' ')
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		++str;
	}
	while (*str > 47 && *str < 58)
	{
		result = (result * 10) + *(str++) - '0';
	}
	return (result * sign);
}
