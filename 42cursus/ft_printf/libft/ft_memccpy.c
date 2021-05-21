/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:46:18 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:54:28 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	char		*dst_ch;
	const char	*src_ch;
	size_t		i;

	dst_ch = (char *)dst;
	src_ch = (const char *)src;
	i = -1;
	while (++i < len)
	{
		dst_ch[i] = src_ch[i];
		if (src_ch[i] == (unsigned char)c)
			return (dst_ch + i + 1);
	}
	return (0);
}
