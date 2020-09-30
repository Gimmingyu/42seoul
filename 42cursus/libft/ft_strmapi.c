/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:06:34 by kyekim            #+#    #+#             */
/*   Updated: 2020/09/30 20:08:18 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (0);
	i = 0;
	while (s[i])
		++i;
	if (!(res = (char *)malloc((i + 1) * sizeof(char))))
		return (0);
	res[i] = 0;
	while (--i)
		res[i] = f(i, s[i]);
	res[0] = f(0, s[0]);
	return (res);
}
