/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 11:39:00 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 14:10:45 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i + 1);
}

char	*ft_strdup(char *src)
{
	unsigned int	length;
	unsigned int	count;
	char			*dest;

	length = ft_strlen(src);
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
