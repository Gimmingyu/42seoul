/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:16:12 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:16:13 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s_cpy;

	i = 0;
	j = start;
	s_cpy = NULL;
	if (s)
	{
		if (!(s_cpy = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (i < len)
		{
			s_cpy[i] = s[j];
			i++;
			j++;
		}
		s_cpy[i] = '\0';
		return (s_cpy);
	}
	return (NULL);
}
