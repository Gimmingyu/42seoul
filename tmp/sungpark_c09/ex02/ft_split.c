/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungpark <sungpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:38:02 by sungpark          #+#    #+#             */
/*   Updated: 2020/07/15 14:43:07 by sungpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_no;
int g_charset[256] = {0, };

char	**str_allocate(char *str)
{
	int		flag;
	char	**output;

	g_no = 0;
	flag = 0;
	while (*str != '\0')
	{
		if (flag && g_charset[(unsigned char)(*str)] == 1)
		{
			flag = 0;
			g_no++;
		}
		else if (g_charset[(unsigned char)(*str)] == 0)
			flag = 1;
		str++;
	}
	if (g_charset[(unsigned char)*(str - 1)] == 0)
		g_no++;
	output = (char **)malloc(sizeof(char *) * (g_no + 1));
	return (output);
}

char	*save_str(char **str, int size)
{
	char	*output;
	int		cnt;
	int		flag;

	flag = 0;
	cnt = 0;
	output = (char *)malloc(sizeof(char) * (size + 1));
	while (**str != '\0')
	{
		if (g_charset[(unsigned char)(**str)] == 0)
		{
			output[cnt++] = **str;
			flag = 1;
		}
		else if (g_charset[(unsigned char)(**str)] == 1 && flag == 1)
			break ;
		(*str)++;
	}
	output[cnt] = '\0';
	return (output);
}

int		word_size(char *str)
{
	int cnt;
	int flag;

	flag = 0;
	cnt = 0;
	while (*str != '\0')
	{
		if (g_charset[(unsigned char)(*str)] == 0)
		{
			cnt++;
			flag = 1;
		}
		else if (g_charset[(unsigned char)(*str)] == 1 && flag == 1)
			break ;
		str++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	char	**output;
	int		size;
	int		idx;

	while (*charset != '\0')
	{
		g_charset[(unsigned char)(*charset)] = 1;
		charset++;
	}
	g_charset[0] = 1;
	output = str_allocate(str);
	idx = 0;
	while (*str != '\0')
	{
		if (g_charset[(unsigned char)(*str)] == 0)
		{
			size = word_size(str);
			output[idx++] = save_str(&str, size);
			continue ;
		}
		str++;
	}
	output[g_no] = 0;
	return (output);
}
