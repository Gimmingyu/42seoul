/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:48:35 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:54:39 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (len == 0)
		return (0);
	str1 = (unsigned char *)b1;
	str2 = (unsigned char *)b2;
	i = -1;
	while (++i < len)
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
	return (0);
}
