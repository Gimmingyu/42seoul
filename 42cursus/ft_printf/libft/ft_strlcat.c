/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:45:29 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:56:49 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i])
		++i;
	while (src[j] && j + i + 1 < size)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = 0;
	while (src[j])
		++j;
	if (i > size)
		return (j + size);
	return (j + i);
}
