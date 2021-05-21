/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:49:33 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:57:36 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (len)
	{
		i = 0;
		while (s1[i] != 0 && s2[i] != 0 && i < len)
		{
			if (s1[i] != s2[i])
				return ((unsigned char)s1[i] - (unsigned char)s2[i]);
			++i;
		}
		if (i != len)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
