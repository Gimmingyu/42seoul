/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 17:00:20 by jipark            #+#    #+#             */
/*   Updated: 2020/04/06 17:09:44 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_range_exception(const char *nptr, int i, int is_minus)
{
	unsigned long long tmp;

	tmp = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		tmp = (tmp * 10) + nptr[i] - '0';
		i++;
	}
	if (is_minus == -1 && tmp > (unsigned long long)LLONG_MAX + 1)
		return (0);
	else if (is_minus == 1 && tmp > (unsigned long long)LLONG_MAX)
		return (-1);
	return (1);
}

int				ft_atoi(const char *nptr)
{
	int i;
	int is_minus;
	int result;
	int exception;

	i = 0;
	result = 0;
	is_minus = 1;
	while (nptr[i] == ' ' || (9 <= nptr[i] && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_minus = -1;
		i++;
	}
	if ((exception = check_range_exception(nptr, i, is_minus)) != 1)
		return (exception);
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		result = (result * 10) + nptr[i] - '0';
		i++;
	}
	return (result * is_minus);
}
