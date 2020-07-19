/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:55:37 by jipark            #+#    #+#             */
/*   Updated: 2020/02/09 22:12:28 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

/*
**	[ft_strlen] function calculate the length of parameter except NULL.
*/

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
**	[ft_strcmp] function compare two string, and return the difference of
**	ASCII.
*/

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int s1_value;
	unsigned int s2_value;
	unsigned int count;

	count = 0;
	s1_value = 0;
	s2_value = 0;
	while (s1[count] != '\0' || s2[count] != '\0')
	{
		s1_value += (unsigned char)s1[count];
		s2_value += (unsigned char)s2[count];
		if (s1[count] != s2[count])
			return (s1_value - s2_value);
		count++;
	}
	return (0);
}

/*
**	[ft_strdup] function duplicates src string from start to end - 1 index.
*/

char	*ft_strdup(char *src, int start, int end)
{
	int		length;
	char	*dest;
	int		i;

	length = end - start;
	dest = malloc(sizeof(char) * length + 1);
	if (!dest)
		return (0);
	i = 0;
	while (i < length)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
**	[ft_putstr] function displays all the elements of parameter excpet NULL.
*/

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	if (g_is_blank == 1)
		write(1, " ", 1);
	if (g_is_blank == 0)
		g_is_blank = 1;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
