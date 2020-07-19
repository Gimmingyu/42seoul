/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:00:01 by jko               #+#    #+#             */
/*   Updated: 2020/02/12 23:49:29 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_strs(char **strs, int size)
{
	int i;

	i = 0;
	if (size <= 0)
	{
		while (strs[i])
			free(strs[i++]);
	}
	else
	{
		while (i < size)
			free(strs[i++]);
	}
	free(strs);
}

int		ft_strlen(char *str)
{
	int len;

	if (str == 0)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup_and_strcat(char *str, char *src, int size)
{
	char	*result;
	int		str_len;
	int		src_len;
	int		i;

	str_len = 0;
	while (str && str[str_len])
		str_len++;
	src_len = 0;
	while (src[src_len] && src[src_len] != '\n' && src_len < size)
		src_len++;
	if ((result = (char *)malloc(sizeof(char) * (str_len + src_len + 1))) == 0)
		return (0);
	i = -1;
	while (str && str[++i])
		result[i] = str[i];
	i = 0;
	while (src[i] && src[i] != '\n' && i < size)
	{
		result[str_len + i] = src[i];
		i++;
	}
	result[str_len + i] = 0;
	free(str);
	return (result);
}
