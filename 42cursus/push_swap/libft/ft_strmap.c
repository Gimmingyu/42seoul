/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:14:51 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:14:52 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s_cpy;

	i = 0;
	s_cpy = NULL;
	if (s && f)
	{
		if (!(s_cpy = ft_strdup(s)))
			return (NULL);
		while (s[i])
		{
			s_cpy[i] = f(s[i]);
			i++;
		}
		s_cpy[i] = '\0';
	}
	return (s_cpy);
}
