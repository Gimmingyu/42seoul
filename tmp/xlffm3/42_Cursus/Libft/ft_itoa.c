/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:52:07 by jipark            #+#    #+#             */
/*   Updated: 2020/04/06 12:27:37 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_size(unsigned int tmp, int is_minus)
{
	int size;

	size = 0;
	if (is_minus || !tmp)
		size++;
	while (tmp != 0)
	{
		tmp /= 10;
		size++;
	}
	return (size);
}

static void	set_result_array(char *result, unsigned int tmp, int index)
{
	if (tmp >= 10)
		set_result_array(result, tmp / 10, index - 1);
	result[index] = (tmp % 10) + '0';
}

char		*ft_itoa(int n)
{
	unsigned int	tmp;
	char			*result;
	int				is_minus;
	int				size;

	is_minus = 0;
	if (n < 0)
	{
		is_minus = 1;
		tmp = -1 * n;
	}
	else
		tmp = n;
	size = get_number_size(tmp, is_minus);
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (is_minus)
		result[0] = '-';
	set_result_array(result, tmp, size - 1);
	result[size] = '\0';
	return (result);
}
