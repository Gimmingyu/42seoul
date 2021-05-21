/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:55:04 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:55:16 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)dst;
	i = -1;
	while (++i < len)
		temp[i] = (unsigned char)c;
	return (dst);
}
