/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongckim <yongckim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 22:12:43 by yongckim          #+#    #+#             */
/*   Updated: 2020/07/16 12:36:03 by yongckim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(int size, char **strs, char *sep)
{
	int i;
	int cnt;
	int len;

	i = 0;
	len = 0;
	while (i < size)
	{
		cnt = 0;
		while (strs[i][cnt])
			cnt++;
		len += cnt;
		i++;
	}
	cnt = 0;
	while (sep[cnt])
		cnt++;
	len += (cnt * (size - 1)) + 1;
	return (len);
}

char	*join_string(int size, char **strs, char *sep, int len)
{
	int		val;
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * len);
	val = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[val++] = strs[i][j++];
		if (i != size - 1)
		{
			j = 0;
			while (sep[j])
				str[val++] = sep[j++];
		}
		i++;
	}
	str[val] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = '\0';
		return (str);
	}
	len = ft_strlen(size, strs, sep);
	str = join_string(size, strs, sep, len);
	return (str);
}
