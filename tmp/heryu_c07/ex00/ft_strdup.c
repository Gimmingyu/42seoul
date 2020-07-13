/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:10:13 by heryu             #+#    #+#             */
/*   Updated: 2020/07/11 21:42:57 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}

char	*ft_strdup(char *src)
{
	int		size;
	char	*ret;

	size = ft_strlen(src);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == (void*)(0))
	{
		errno = ENOMEM;
		return (void*)(0);
	}
	ft_strcpy(ret, src);
	return (ret);
}
