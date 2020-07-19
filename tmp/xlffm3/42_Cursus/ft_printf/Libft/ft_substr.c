/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:39:00 by jipark            #+#    #+#             */
/*   Updated: 2020/02/26 20:39:00 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	s_len;
	size_t			i;

	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	s_len = ft_strlen(s);
	if (start <= s_len)
	{
		while (i < len)
		{
			result[i] = s[start + i];
			i++;
		}
	}
	result[i] = '\0';
	return (result);
}
