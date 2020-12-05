/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:30:16 by kyekim            #+#    #+#             */
/*   Updated: 2020/12/02 20:34:55 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	isset(char a, char const *set)
{
	int	index;

	index = 0;
	while (set[index])
	{
		if (a == set[index])
			return (true);
		index++;
	}
	return (false);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		index2;
	int		index3;
	char	*ans;

	if (!s1 || !set)
		return (ft_strdup(""));
	index = 0;
	index2 = ft_strlen(s1) - 1;
	index3 = 0;
	while (isset(s1[index], set) && s1[index])
		index++;
	while (isset(s1[index2], set) && index2)
		index2--;
	if ((index2 - index) <= 0)
		return (ft_strdup(""));
	if (!(ans = malloc(sizeof(char) * ((index2 - index) + 2))))
	{
		ans = malloc(0);
		return (ans);
	}
	while (index <= index2)
		ans[index3++] = s1[index++];
	ans[index3] = '\0';
	return (ans);
}
