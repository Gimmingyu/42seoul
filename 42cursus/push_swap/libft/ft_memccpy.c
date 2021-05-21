/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:01:06 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:01:07 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*cpy_src;
	unsigned char	*cpy_dst;

	i = 0;
	cpy_src = ((unsigned char*)src);
	cpy_dst = ((unsigned char*)dst);
	while (i < n)
	{
		cpy_dst[i] = cpy_src[i];
		if ((cpy_src)[i] == (unsigned char)c)
			return (cpy_dst + i + 1);
		i++;
	}
	return (NULL);
}
