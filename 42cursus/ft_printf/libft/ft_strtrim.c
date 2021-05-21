/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:58:08 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:58:09 by kyekim           ###   ########.fr       */
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
	char	*result;
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
	if (!(result = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	result[i] = 0;
	if (i)
		while (--i)
			result[i] = s1[i];
	result[0] = s1[0];
	return (result);
}
