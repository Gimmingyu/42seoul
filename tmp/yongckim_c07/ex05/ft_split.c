/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongckim <yongckim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:16:27 by yongckim          #+#    #+#             */
/*   Updated: 2020/07/16 09:05:52 by yongckim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_sep(char c, char *charset)
{
	unsigned int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		cut_strlen(char *str, char *charset)
{
	int i;
	int cut;

	cut = 0;
	i = 0;
	while (str[i])
	{
		if (!(check_sep(str[i], charset)))
			cut++;
		else if (check_sep(str[i], charset))
			break ;
		i++;
	}
	return (cut);
}

char	**str_split(char **dest, char *str, char *charset, int cut)
{
	int	st;
	int end;
	int cnt;
	int i;

	st = 0;
	cnt = 0;
	while (cnt < cut)
	{
		while (check_sep(str[st], charset) && str[st])
			st++;
		end = st;
		while (!check_sep(str[end], charset) && str[end])
			end++;
		dest[cnt] = (char *)malloc(sizeof(char) * (end - st) + 1);
		i = -1;
		while (++i < end - st)
			dest[cnt][i] = str[st + i];
		dest[cnt][i] = 0;
		st = end;
		cnt++;
	}
	dest[cnt] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		cut;
	char	**split;

	cut = cut_strlen(str, charset);
	split = (char **)malloc(sizeof(char *) * cut + 1);
	split = str_split(split, str, charset, cut);
	return (split);
}
