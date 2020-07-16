/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 14:27:35 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/16 14:28:05 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_length(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		str_cat(char *dest, int index, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[index + i] = src[i];
		i++;
	}
	return (index + i);
}

char	*make_blank_str(void)
{
	char *result;

	result = (char *)malloc(sizeof(char) * 1);
	result[0] = 0;
	return (result);
}

void	cat_strs(char **strs, char *sep, char *result, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = str_cat(result, j, strs[i]);
		if (i < size - 1)
			j = str_cat(result, j, sep);
		i++;
	}
	result[j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		length;
	char	*result;

	if (size == 0)
	{
		result = make_blank_str();
		return (result);
	}
	length = get_length(sep) * (size - 1);
	i = 0;
	while (i < size)
		length += get_length(strs[i++]);
	result = (char *)malloc(sizeof(char) * (length + 1));
	cat_strs(strs, sep, result, size);
	return (result);
}
