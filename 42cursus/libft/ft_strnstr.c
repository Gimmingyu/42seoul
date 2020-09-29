/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:40:40 by kyekim            #+#    #+#             */
/*   Updated: 2020/09/29 21:43:40 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_len;
	size_t	needle_len;
	size_t	len2;
	size_t	i;

	if (needle[0] == 0)
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (haystack_len < needle_len || len < needle_len)
		return (0);
	len2 = haystack_len > len ? len : haystack_len;
	i = 0;
	while (i + needle_len <= len2)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
