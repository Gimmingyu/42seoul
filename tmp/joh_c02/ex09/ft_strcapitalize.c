/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:05:19 by joh               #+#    #+#             */
/*   Updated: 2020/07/08 15:32:52 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_alpha(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int		index;
	int		trf;

	index = 0;
	trf = 1;
	while (str[index] != '\0')
	{
		if (is_alpha(str[index]) || is_number(str[index]))
		{
			if (trf && (str[index] >= 'a' && str[index] <= 'z'))
			{
				str[index] = str[index] - 32;
			}
			else if (!trf && (str[index] >= 'A' && str[index] <= 'Z'))
			{
				str[index] = str[index] + 32;
			}
			trf = 0;
		}
		else
			trf = 1;
		index++;
	}
	return (str);
}
