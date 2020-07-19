/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:07:13 by jipark            #+#    #+#             */
/*   Updated: 2020/04/07 17:48:08 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_return(int res, int fd, char **line, char *tmp[])
{
	if (res <= 0 && res != -3)
	{
		if (tmp[fd])
		{
			free(tmp[fd]);
			tmp[fd] = NULL;
		}
	}
	if (res == -2 || res == -3)
		return (-1);
	if (*line == NULL)
	{
		if (!(*line = (char *)malloc(sizeof(char))))
			return (-1);
		(*line)[0] = '\0';
	}
	if (!res)
		return (0);
	return (1);
}

int		ft_strlen(char *src)
{
	int len;

	len = 0;
	while (src && src[len] != '\0')
		len++;
	return (len);
}

void	ft_bufcpy(char *tmp, char *buf, int idx)
{
	int i;

	i = 0;
	while (idx < BUFFER_SIZE)
	{
		tmp[i] = buf[idx];
		i++;
		idx++;
	}
	tmp[i] = '\0';
}

char	*ft_strdup(char *src, int start, int end)
{
	char	*dest;
	int		i;
	int		len;

	len = end - start;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	i = 0;
	while (i < (s1_len + s2_len))
	{
		if (i < s1_len)
			result[i] = s1[i];
		else
			result[i] = s2[i - s1_len];
		i++;
	}
	result[i] = '\0';
	if (s1)
		free(s1);
	return (result);
}
