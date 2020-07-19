/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 08:29:37 by jipark            #+#    #+#             */
/*   Updated: 2020/01/28 10:55:14 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *str)
{
	long long	result;
	int			count;
	int			is_minus;

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
	return ((int)(result * is_minus));
}
