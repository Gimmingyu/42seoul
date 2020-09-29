/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 22:07:01 by kyekim            #+#    #+#             */
/*   Updated: 2020/09/29 22:08:23 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	c2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst2[i] = src2[i];
		if (dst2[i] == c2)
			return (dst2 + i + 1);
		i++;
	}
	return (0);
}
