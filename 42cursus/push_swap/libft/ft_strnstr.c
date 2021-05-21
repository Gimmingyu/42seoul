/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:15:35 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:15:36 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = ft_strlen(needle);
	j = 0;
	if (size == 0)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		i = 0;
		while (haystack[j + i] == needle[i] && (i + j) < len)
		{
			i++;
			if (!needle[i])
				return ((char *)&haystack[j]);
		}
		j++;
	}
	return (NULL);
}
