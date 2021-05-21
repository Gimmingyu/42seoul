/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:14:04 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:14:05 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	if (size <= len_dst)
		return (ft_strlen(src) + size);
	else
	{
		ft_strncat(dst, src, (size - len_dst - 1));
		return (ft_strlen(src) + len_dst);
	}
}
