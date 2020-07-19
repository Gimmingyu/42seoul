/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:17:09 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/31 13:16:03 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_strlen(int size, char **strs, char *sep)
{
	int i;
	int cnt;
	int	len;

	i = 0 - 1;
	len = 0;
	while (++i < size)
	{
		cnt = 0;
		while (strs[i][cnt])
			cnt++;
		len += cnt;
	}
	cnt = 0;
	while (sep[cnt])
		cnt++;
	len += (cnt * (size - 1)) + 1;
	return (len);
}

char	*get_string(int size, char **strs, char *sep, int len)
{
	int		index;
	int		i;
	int		j;
	char	*str;

	str = (char *)malloc(sizeof(char) * len);
	index = 0;
	i = 0 - 1;
	while (++i < size)
	{
		j = 0 - 1;
		while (strs[i][++j])
			str[index++] = strs[i][j];
		if (i != size - 1)
		{
			j = 0 - 1;
			while (sep[++j])
				str[index++] = sep[j];
		}
	}
	str[index] = 0;
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	char	*str;

	if (!size)
	{
		str = (char *)malloc(sizeof(char) * 1);
		str[0] = 0;
		return (str);
	}
	len = get_strlen(size, strs, sep);
	str = get_string(size, strs, sep, len);
	return (str);
}
