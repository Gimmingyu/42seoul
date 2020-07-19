/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:39:00 by jipark            #+#    #+#             */
/*   Updated: 2020/01/30 17:18:34 by jipark           ###   ########.fr       */
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
