/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:30:16 by kyekim            #+#    #+#             */
/*   Updated: 2020/09/30 19:38:01 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_istrim(char c, char const *set)
{
	size_t	i;

	i = -1;
	while (set[++i])
		if (c == set[i])
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	len;

	if (!s1)
		return (0);
	while (ft_istrim(*s1, set))
		++s1;
	i = -1;
	while (s1[++i])
	{
		if (!(ft_istrim(s1[i], set)))
			len = 0;
		else
			++len;
	}
	i -= len;
	if (!(res = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	res[i] = 0;
	if (i)
		while (--i)
			res[i] = s1[i];
	res[0] = s1[0];
	return (res);
}
