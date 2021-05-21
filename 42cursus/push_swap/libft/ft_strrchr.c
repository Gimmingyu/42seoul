/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:15:43 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:15:44 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == ((char)c))
			return ((char*)s + i);
		i--;
	}
	if (s[0] == ((char)c))
		return ((char*)s);
	return (0);
}
