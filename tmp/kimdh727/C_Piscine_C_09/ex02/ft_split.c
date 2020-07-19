/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:48:35 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/11 00:43:28 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_sep(char c, char *charset)
{
	unsigned int i;

	i = 0 - 1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int		get_size(char *str, char *charset)
{
	int i;
	int status;
	int cnt;

	i = 0 - 1;
	status = 0;
	cnt = 0;
	while (str[++i])
	{
		if (!status && !(check_sep(str[i], charset)))
		{
			status = 1;
			cnt++;
		}
		else if (status && check_sep(str[i], charset))
			status = 0;
	}
	return (cnt);
}

char	**make_split(char **dest, char *str, char *charset, int out_cnt)
{
	int	st;
	int en;
	int cnt;
	int i;

	st = 0;
	cnt = 0 - 1;
	while (++cnt < out_cnt)
	{
		while (check_sep(str[st], charset) && str[st])
			st++;
		en = st;
		while (!check_sep(str[en], charset) && str[en])
			en++;
		dest[cnt] = (char *)malloc(sizeof(char) * (en - st) + 1);
		i = 0 - 1;
		while (++i < en - st)
			dest[cnt][i] = str[st + i];
		dest[cnt][i] = 0;
		st = en;
	}
	dest[cnt] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		cnt;
	char	**split;

	cnt = get_size(str, charset);
	split = (char **)malloc(sizeof(char *) * cnt + 1);
	split = make_split(split, str, charset, cnt);
	return (split);
}
