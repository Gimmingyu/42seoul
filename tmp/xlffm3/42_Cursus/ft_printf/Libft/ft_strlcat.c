/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:54:52 by jipark            #+#    #+#             */
/*   Updated: 2020/02/25 16:54:52 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t cnt;
	size_t dst_len;
	size_t src_len;

	dst_len = 0;
	src_len = 0;
	while (dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size >= dst_len + 2)
	{
		cnt = 0;
		while (cnt < size - dst_len - 1 && src[cnt] != '\0')
		{
			dst[dst_len + cnt] = src[cnt];
			cnt++;
		}
		dst[dst_len + cnt] = 0;
	}
	if (size >= dst_len)
		return ((dst_len + src_len));
	else
		return ((src_len + size));
}
