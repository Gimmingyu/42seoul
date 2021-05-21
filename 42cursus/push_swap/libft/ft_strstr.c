/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:16:01 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:16:02 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int pos;
	int len;

	i = 0;
	pos = 0;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (needle[pos] == haystack[i + pos])
		{
			if (pos == len - 1)
				return ((char *)haystack + i);
			pos++;
		}
		pos = 0;
		i++;
	}
	return (0);
}
