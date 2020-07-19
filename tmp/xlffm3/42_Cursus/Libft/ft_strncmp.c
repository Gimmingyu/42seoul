/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:56:18 by jipark            #+#    #+#             */
/*   Updated: 2020/02/25 16:56:18 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	s1_value;
	unsigned char	s2_value;
	size_t			i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		s1_value = (unsigned char)s1[i];
		s2_value = (unsigned char)s2[i];
		if (s1[i] != s2[i])
			return ((int)s1_value - (int)s2_value);
		i++;
	}
	return (0);
}
