/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 12:09:55 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/18 21:55:35 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

/*
** [ft_strlen] calc the length of params, except NULL
*/
int		ft_strlen(char *str)
{
	int 	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** [ft_strcmp] compare two string, return the difference of ASCII
*/
int		ft_strcmp(char *str1, char *str2)
{
	while ((*str1 == *str2) && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	return (*(unsigned char*)str1 - *(unsigned char*)str2);
}

/*
** [ft_putstr] print string value
*/
void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
}

char	*ft_strrev(char *str, int len)
{
	int		i;
	char	tmp;

	i = 0;
	while (len - 1 > i)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		len--;
		i++;
	}
	return (str);
}

char	*ft_strcat(char *str1, char *str2)
{
	int		len;
	int		i;

	len = ft_strlen(str1);
	i = 0;
	while (str2[i] != '\0')
		str1[len++] = str2[i++];
	str1[len] = '\0';
	return (str1);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}