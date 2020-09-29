/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 22:00:37 by kyekim            #+#    #+#             */
/*   Updated: 2020/09/29 22:10:18 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*addr;
	unsigned char	tmp;

	i = 0;
	addr = (unsigned char *)b;
	tmp = (unsigned char)c;
	while (i < len)
	{
		addr[i] = tmp;
		i++;
	}
	return (b);
}
