/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:48:35 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/09 20:25:02 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdlib.h>

/*
** 		int		check_sep(char c, char *charset)
**		설명 : 한줄의 문자열과 개행 문자를  매개변수로 받아  문자열에 개행 문자가 포함되어 있는지 검사!
**		반환값 : 개행 문자가 포함되어 있으면 1을 반환! 아니면 0을 반환!
*/

int		check_sep(char c, char *charset)
{
	unsigned int i;

	i = 0 - 1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

/*
**	int	get_size(char *str, char *charset)
**	설명 : set이 있는지 없는지 체크하고 set의 갯수를 센다.
**	반환값 : set 갯수를 반환한다.
*/

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

/*
**	char	**make_split(char **dest, char *str, char *charset, int out_cnt)
**	설명 :	set을 기준으로 문자열 2개를 복사한다.
**	반환값 : 문자열 배열 포인터를 반환한다.
*/

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
		if (!(dest[cnt] = (char *)malloc(sizeof(char) * (en - st) + 1)))
			return (0);
		i = 0 - 1;
		while (++i < en - st)
			dest[cnt][i] = str[st + i];
		dest[cnt][i] = 0;
		st = en;
	}
	dest[cnt] = 0;
	return (dest);
}

/*
**	void	free_split(int cnt, char **split)
**	설명 : split에 할당된 메모리를 해제한다.
*/

void	free_split(int cnt, char **split)
{
	int	i;

	i = 0 - 1;
	while (++i < cnt)
		free(split[i]);
	free(split);
}

/*
**	char	**ft_split(char *str, char *charset)
**	설명 : split 문자열 배열에 메모리를 할당하고, split을 실행한다.
**	반환값 : split이 제대로 됬다면 문자열 배열 포인터를, 아닌 경우에는 널 포인터를 반환한다.
*/

char	**ft_split(char *str, char *charset)
{
	int		cnt;
	char	**split;

	cnt = get_size(str, charset);
	if (!(split = (char **)malloc(sizeof(char *) * cnt + 1)))
		return (0);
	if (!(split = make_split(split, str, charset, cnt)))
	{
		free_split(cnt, split);
		return (0);
	}
	return (split);
}
