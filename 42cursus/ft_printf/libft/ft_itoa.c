/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:52:12 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:52:25 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				sign;
	int				len;
	char			*result;

	sign = 0;
	len = 1;
	if (n < 0)
	{
		sign = 1;
		++len;
		n *= -1;
	}
	nb = (unsigned int)n;
	while (n /= 10)
		++len;
	if (!(result = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	if (sign)
		result[0] = '-';
	result[len] = 0;
	result[--len] = (nb % 10) + '0';
	while (nb /= 10)
		result[--len] = (nb % 10) + '0';
	return (result);
}
