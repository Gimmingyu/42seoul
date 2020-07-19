/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 19:52:24 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 20:35:25 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strdup(char *str, int start, int len)
{
	char	*result;
	int		i;

	if (len <= 0)
		return (0);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

void	ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				len;
	unsigned int	idx;

	len = 0;
	idx = 0;
	while (dest[len] != '\0')
		len++;
	while (idx < nb)
	{
		dest[len + idx] = src[idx];
		if (src[idx] == '\0')
			break ;
		idx++;
	}
	if (idx == nb)
		dest[len + idx] = '\0';
}

void	ft_strcpy(char *dest, char *src)
{
	int		idx;

	idx = 0;
	while (1)
	{
		dest[idx] = src[idx];
		if (src[idx] == '\0')
			break ;
		idx++;
	}
}

void	free_strs(char **strs, int size)
{
	int i;

	i = 0;
	if (size < 0)
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
	else
		while (i < size)
		{
			free(strs[i]);
			i++;
		}
	free(strs);
}
