/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:50:11 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:54:52 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_ch;
	const unsigned char	*src_ch;
	size_t				i;

	if (len == 0)
		return (dst);
	dst_ch = (unsigned char *)dst;
	src_ch = (const unsigned char *)src;
	if (src_ch < dst_ch)
	{
		while (--len)
			dst_ch[len] = src_ch[len];
		dst_ch[0] = src_ch[0];
	}
	else
	{
		i = -1;
		while (++i < len)
			dst_ch[i] = src_ch[i];
	}
	return (dst);
}
