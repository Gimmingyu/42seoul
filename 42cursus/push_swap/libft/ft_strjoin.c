/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:11:48 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:11:50 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	char	*s_final;
	size_t	size;

	if (s1 && s2)
	{
		s_final = NULL;
		size = (ft_strlen(s1) + (ft_strlen(s2)));
		if (!(s_final = (char*)malloc(sizeof(char) * size + 1)))
			return (NULL);
		*(s_final + size) = '\0';
		ft_strcpy(s_final, s1);
		ft_strcat(s_final, s2);
		return (s_final);
	}
	return (0);
}
