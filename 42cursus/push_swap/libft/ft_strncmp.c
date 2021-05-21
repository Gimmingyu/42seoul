/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:15:08 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:15:09 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n)
	{
		while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
			i++;
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
