/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:27:25 by kyekim            #+#    #+#             */
/*   Updated: 2020/09/30 23:52:46 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		++s1_len;
	while (s2[s2_len])
		++s2_len;
	if (!(res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char))))
		return (0);
	res[s1_len + s2_len] = 0;
	if (s2_len)
		while (--s2_len)
			res[s1_len + s2_len] = s2[s2_len];
	res[s1_len] = s2[0];
	if (s1_len)
		while (--s1_len)
			res[s1_len] = s1[s1_len];
	if (s1[0])
		res[0] = s1[0];
	return (res);
}
