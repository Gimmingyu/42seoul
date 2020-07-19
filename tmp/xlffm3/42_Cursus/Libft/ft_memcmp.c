/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:59:15 by jipark            #+#    #+#             */
/*   Updated: 2020/04/06 14:37:08 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_tmp;
	const unsigned char	*s2_tmp;
	size_t				i;

	s1_tmp = (const unsigned char *)s1;
	s2_tmp = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s1_tmp[i] != s2_tmp[i])
			return ((int)s1_tmp[i] - (int)s2_tmp[i]);
		i++;
	}
	return (0);
}
