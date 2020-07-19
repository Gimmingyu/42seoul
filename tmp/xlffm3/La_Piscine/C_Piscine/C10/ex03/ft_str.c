/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:25:29 by jipark            #+#    #+#             */
/*   Updated: 2020/02/12 13:50:30 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		ft_strlen(char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	unsigned int	length;
	unsigned int	count;
	char			*dest;

	length = ft_strlen(src + 1);
	dest = malloc(sizeof(char) * length);
	if (!dest)
		return (0);
	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int s1_value;
	unsigned int s2_value;
	unsigned int count;

	count = 0;
	s1_value = 0;
	s2_value = 0;
	while (s1[count] != '\0' || s2[count] != '\0')
	{
		s1_value += (unsigned char)s1[count];
		s2_value += (unsigned char)s2[count];
		if (s1[count] != s2[count])
			return (s1_value - s2_value);
		count++;
	}
	return (0);
}
