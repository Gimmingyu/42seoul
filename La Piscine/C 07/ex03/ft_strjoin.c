/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 12:48:29 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 14:12:20 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	get_strs_length(int size, char **strs)
{
	unsigned int	length;
	int				i;
	int				j;

	length = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			length++;
			j++;
		}
		i++;
	}
	return (length);
}

unsigned int	get_sep_length(char *sep)
{
	unsigned int i;

	i = 0;
	while (sep[i] != '\0')
		i++;
	return (i);
}

void			*get_dest(char *dest, char **strs, char *sep, int size)
{
	int i;
	int j;
	int count;

	i = -1;
	count = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			dest[count] = strs[i][j];
			count++;
			j++;
		}
		j = 0;
		while (i != size - 1 && sep[j] != '\0')
		{
			dest[count] = sep[j];
			count++;
			j++;
		}
	}
	dest[count] = '\0';
	return (dest);
}

char			*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	strs_length;
	unsigned int	sep_length;
	char			*dest;

	if (size == 0)
	{
		dest = (char *)malloc(sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	strs_length = get_strs_length(size, strs);
	sep_length = get_sep_length(sep);
	dest = (char *)malloc(1 + sizeof(char) * strs_length +
	sizeof(char) * sep_length * (size - 1));
	get_dest(dest, strs, sep, size);
	return (dest);
}
