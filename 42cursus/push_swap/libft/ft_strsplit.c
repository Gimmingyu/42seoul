/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:15:55 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:15:56 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *str, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int		ft_lenwords(char const *str, char c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**s2;

	if (!s || !(s2 = (char **)malloc(sizeof(*s2) *
		(ft_countwords(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_countwords(s, c))
	{
		k = 0;
		if (!(s2[i] = ft_strnew(ft_lenwords(&s[j], c) + 1)))
			s2[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			s2[i][k++] = s[j++];
		s2[i][k] = '\0';
	}
	s2[i] = 0;
	return (s2);
}
