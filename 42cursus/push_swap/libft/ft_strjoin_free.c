/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:13:56 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:13:57 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int i)
{
	char *tmp;

	if (s1 && s2)
	{
		tmp = ft_strjoin(s1, s2);
		if (i == 1)
			free(s1);
		else if (i == 2)
			free(s2);
		else if (i == 3)
		{
			free(s1);
			free(s2);
		}
		return (tmp);
	}
	return (0);
}
