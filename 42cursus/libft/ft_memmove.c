/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 22:13:24 by kyekim            #+#    #+#             */
/*   Updated: 2020/09/30 03:23:20 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst2;
	char	*src2;
	size_t	i;

	dst2 = dst;
	src2 = (char *)src;
	i = -1;
	if (dst2 > src2)
		while ((int)(--n) >= 0)
			dst2[n] = src2[n];
	else
		while (++i < n)
			dst2[i] = src2[i];
	return (dst);
}
