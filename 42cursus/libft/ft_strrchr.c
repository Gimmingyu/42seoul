/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 21:38:22 by kyekim            #+#    #+#             */
/*   Updated: 2020/09/29 21:51:15 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ss;
	char	cc;

	ss = (char *)s;
	cc = (char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (ss[i] == cc)
			return (ss + i);
		i--;
	}
	if (ss[i] == cc)
		return (ss);
	return (0);
}
