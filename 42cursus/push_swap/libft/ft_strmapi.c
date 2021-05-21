/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chcoutur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:20:37 by chcoutur          #+#    #+#             */
/*   Updated: 2018/12/10 09:54:57 by chcoutur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s_cpy;

	i = 0;
	s_cpy = NULL;
	if (s && f)
	{
		if (!(s_cpy = ft_strdup(s)))
			return (NULL);
		while (s[i])
		{
			s_cpy[i] = f(i, s[i]);
			i++;
		}
		s_cpy[i] = '\0';
	}
	return (s_cpy);
}
