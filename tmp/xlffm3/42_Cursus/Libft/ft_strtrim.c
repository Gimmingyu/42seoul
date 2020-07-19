/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:56:48 by jipark            #+#    #+#             */
/*   Updated: 2020/04/06 12:31:28 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_set(char const c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		get_prefix_len(char const *s1, char const *set)
{
	int i;
	int prefix_len;

	i = 0;
	prefix_len = 0;
	while (s1[i] != '\0' && (is_set(s1[i], set)))
	{
		i++;
		prefix_len++;
	}
	return (prefix_len);
}

static int		get_suffix_len(char const *s1, char const *set, int index)
{
	int suffix_len;

	suffix_len = 0;
	while (index >= 0 && (is_set(s1[index], set)))
	{
		index--;
		suffix_len++;
	}
	return (suffix_len);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		s1_len;
	int		prefix_len;
	int		suffix_len;
	int		i;

	s1_len = ft_strlen(s1);
	prefix_len = get_prefix_len(s1, set);
	if (s1_len == prefix_len)
		return (ft_strdup(""));
	suffix_len = get_suffix_len(s1, set, s1_len - 1);
	if (!(result = (char *)malloc(sizeof(char) *
					(s1_len - prefix_len - suffix_len + 1))))
		return (0);
	i = 0;
	result[s1_len - prefix_len - suffix_len] = '\0';
	s1_len = s1_len - prefix_len - suffix_len;
	while (i < s1_len)
	{
		result[i] = s1[prefix_len];
		i++;
		prefix_len++;
	}
	return (result);
}
