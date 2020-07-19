/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:02:31 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/11 22:41:55 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	return (str_len);
}

int		ft_strarrlen(char **strarr)
{
	int	strarr_len;

	strarr_len = 0;
	while (strarr[strarr_len])
		strarr_len++;
	return (strarr_len);
}

int		ft_atoi(char *str)
{
	int	i;
	int len;
	int	result;

	if (str[0] == '0')
		return (0);
	i = 0 - 1;
	len = ft_strlen(str);
	result = 0;
	while (++i < len)
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
			return (0);
	}
	return (result);
}

char	*ft_strdup(char *str, int st, int en, int size)
{
	int		i;
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	i = 0 - 1;
	while (++i < en - st)
		dest[i] = str[st + i];
	dest[i] = 0;
	return (dest);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
