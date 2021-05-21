/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 20:43:22 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:56:34 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		src_len;
	char	*result;

	src_len = 0;
	while (src[src_len])
		++src_len;
	result = (char *)malloc(sizeof(char) * (src_len + 1));
	while (src_len > -1)
	{
		result[src_len] = src[src_len];
		--src_len;
	}
	return (result);
}
