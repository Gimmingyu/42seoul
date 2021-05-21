/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:56:18 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:56:20 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	*ft_countalloc(size_t *count)
{
	size_t	*result;
	size_t	count_count;

	if ((result = (size_t *)malloc((*count + 1) * sizeof(size_t))))
	{
		count_count = -1;
		while (++count_count < *count)
			result[count_count] = count[count_count];
	}
	free(count);
	return (result);
}

static size_t	*ft_countwd(char const *s, char c)
{
	size_t	*count;
	size_t	flag;

	if (!(count = (size_t *)malloc(sizeof(size_t))))
		return (0);
	*count = 0;
	flag = 0;
	while (*s)
		if (!flag)
			if (*s == c)
				++s;
			else
			{
				flag = ++count[0];
				if (!(count = ft_countalloc(count)))
					return (0);
				count[flag] = 0;
			}
		else if (*(s++) != c)
			++count[flag];
		else
			flag = 0;
	return (count);
}

static void		ft_makestrs(char **strs, size_t *count, char const *s, char c)
{
	size_t	i;

	strs[*count] = 0;
	while (*strs)
	{
		if (*s == c)
		{
			++s;
			continue ;
		}
		++count;
		i = -1;
		while (--(*count))
			(*strs)[++i] = *(s++);
		(*strs)[++i] = *(s++);
		(*strs)[++i] = 0;
		++strs;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	*count;
	size_t	i;

	if (!s)
		return (0);
	if (!(count = ft_countwd(s, c)))
		return (0);
	if ((strs = (char **)malloc((*count + 1) * sizeof(char *))))
	{
		i = -1;
		while (++i < *count)
			if (!(strs[i] = (char *)malloc((count[i + 1] + 1) * sizeof(char))))
			{
				while (i--)
					free(strs[i]);
				free(strs);
			}
		if (i == *count)
			ft_makestrs(strs, count, s, c);
		else
			strs = 0;
	}
	free(count);
	return (strs);
}
