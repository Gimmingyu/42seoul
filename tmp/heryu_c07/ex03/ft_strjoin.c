/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heryu <heryu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 23:06:30 by heryu             #+#    #+#             */
/*   Updated: 2020/07/13 20:32:07 by heryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
}

void	strs_join(int size, char **strs, char *sep, char *ret)
{
	int		i;
	int		cur_position;
	int		sep_size;

	i = 0;
	cur_position = 0;
	sep_size = ft_strlen(sep);
	while (i < size)
	{
		ft_strcpy(ret + cur_position, strs[i]);
		cur_position += ft_strlen(strs[i]);
		if (i < size - 1)
		{
			ft_strcpy(ret + cur_position, sep);
			cur_position += sep_size;
		}
		else
			ret[cur_position] = '\0';
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		total_size;
	int		sep_size;
	int		i;

	if (size <= 0)
	{
		ret = (char*)malloc(sizeof(char) * 1);
		ret[0] = '\0';
		return (ret);
	}
	total_size = 0;
	i = 0;
	while (i < size)
		total_size += ft_strlen(strs[i++]);
	sep_size = ft_strlen(sep);
	ret = (char*)malloc(total_size + (sep_size * (size - 1)) + 1);
	if (ret == (void*)(0))
		return (ret);
	strs_join(size, strs, sep, ret);
	return (ret);
}
