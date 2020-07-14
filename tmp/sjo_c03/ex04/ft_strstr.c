/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 03:49:31 by sjo               #+#    #+#             */
/*   Updated: 2020/07/09 10:33:32 by sjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	char *p1;
	char *p2;

	if (*to_find == 0)
		return (char *)str;
	while (*str != 0)
	{
		if (*str == *to_find)
		{
			p1 = str + 1;
			p2 = to_find + 1;
			while (*p2 != 0 && *p1 != 0 && *p1 == *p2)
			{
				p1++;
				p2++;
			}
			if (*p2 == 0)
				return (char *)str;
			if (*p1 == 0)
				break ;
		}
		str++;
	}
	return (NULL);
}
