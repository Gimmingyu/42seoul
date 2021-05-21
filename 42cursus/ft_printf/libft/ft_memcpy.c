/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:49:15 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:54:45 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst_ch;
	const char	*src_ch;

	dst_ch = (char *)dst;
	src_ch = (const char *)src;
	i = -1;
	while (++i < len)
		dst_ch[i] = src_ch[i];
	return (dst);
}
