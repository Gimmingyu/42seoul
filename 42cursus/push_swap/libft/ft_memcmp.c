/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:01:36 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:01:38 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	i = 0;
	if ((s1 == NULL && s2 == NULL) || n <= 0)
		return (0);
	while (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i] && i < n - 1)
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
