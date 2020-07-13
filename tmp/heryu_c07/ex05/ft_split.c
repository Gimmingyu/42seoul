/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 00:35:37 by heryu             #+#    #+#             */
/*   Updated: 2020/07/14 01:52:07 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char ch, char *sep)
{
	int		i;

	i = 0;
	while (sep[i] != '\0')
		if (sep[i++] == ch)
			return (1);
	return (0);
}

int		get_splited_size(char *str, char *sep)
{
	int		size;
	int		i;
	int		flag;

	i = 0;
	while (str[i] != '\0' && !is_sep(str[i], sep))
		i++;
	size = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (flag == 1 && is_sep(str[i], sep))
		{
			size++;
			flag = 0;
		}
		else if (!is_sep(str[i], sep))
			flag = 1;
		i++;
	}
	return (size);
}

void	set_string_address(char **ret, char *str, char *sep)
{
	int		i;
	int		flag;
	int		cnt;

	i = 0;
	while (str[i] != '\0' && !is_sep(str[i], sep))
		i++;
	flag = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (flag != 0 && is_sep(str[i], sep))
		{
			ret[cnt++] = &str[flag];
			flag = 0;
		}
		else if (flag == 0 && !is_sep(str[i], sep))
		{
			flag = i;
		}
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		splited_size;

	splited_size = get_splited_size(str, charset);
	ret = (char**)malloc(sizeof(char*) * (splited_size + 1));
	ret[splited_size] = (void*)0;
	set_string_address(ret, str, charset);
	return (ret);
}
