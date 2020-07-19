/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:41:33 by jipark            #+#    #+#             */
/*   Updated: 2020/04/06 14:31:23 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*tmp_src;
	unsigned char		*tmp_dest;
	size_t				i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	tmp_src = (const unsigned char *)src;
	tmp_dest = (unsigned char *)dest;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest);
}
