/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:02:11 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:02:12 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	char	*b_cpy;

	b_cpy = (char *)b;
	i = 0;
	while (i < n)
	{
		b_cpy[i] = (unsigned char)c;
		i++;
	}
	return (b_cpy);
}
