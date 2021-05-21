/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:47:02 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:54:34 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	i = -1;
	temp = (unsigned char *)b;
	while (++i < len)
		if (temp[i] == (unsigned char)c)
			return (&temp[i]);
	return (0);
}
