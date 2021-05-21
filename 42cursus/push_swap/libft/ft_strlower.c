/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:14:20 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:14:21 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strlower(char *str)
{
	char	*dst;
	int		i;

	dst = str;
	i = 0;
	while (dst[i])
	{
		dst[i] = ft_tolower(dst[i]);
		i++;
	}
	return (dst);
}
