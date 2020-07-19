/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:31:40 by jipark            #+#    #+#             */
/*   Updated: 2020/02/26 16:31:40 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*src_tmp;
	unsigned char		*dest_tmp;
	size_t				i;

	i = 0;
	src_tmp = (const unsigned char *)src;
	dest_tmp = (unsigned char *)dest;
	while (i < n)
	{
		dest_tmp[i] = src_tmp[i];
		if (dest_tmp[i] == (unsigned char)c)
			return ((void *)(dest + i + 1));
		i++;
	}
	return (0);
}
