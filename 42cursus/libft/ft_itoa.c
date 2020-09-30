/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:44:09 by kyekim            #+#    #+#             */
/*   Updated: 2020/09/30 19:46:22 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	int				sign;
	int				len;
	char			*res;

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
	if (!(res = (char *)malloc((len + 1) * sizeof(char))))
		return (0);
	if (sign)
		res[0] = '-';
	res[len] = 0;
	res[--len] = (nb % 10) + '0';
	while (nb /= 10)
		res[--len] = (nb % 10) + '0';
	return (res);
}
