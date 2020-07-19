/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:51:46 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/09 20:26:59 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/*
**	char	*read_buf(char *dict, char *dest)
**	설명 : 딕셔너리 파일을 읽어드린 후, 문자열을 복사한다.
**	반환값 : 복사된 문자열 포인터를 넘긴다.
**	g_flag = 0x100 : 파일 오픈 에러
*/

char	*read_buf(char *dict, char *dest)
{
	int		i;
	int		j;
	char	buf[BUF_SIZE];
	int		buf_len;
	int		fd;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		g_flag |= 0x2100;
		return (0);
	}
	j = 0;
	while ((buf_len = read(fd, buf, BUF_SIZE)))
	{
		i = 0 - 1;
		while (++i < buf_len)
			dest[i + j * BUF_SIZE] = buf[i];
		j++;
	}
	close(fd);
	return (dest);
}

/*
**	char	*get_dict_buf(char *dict)
**	설명 : 파일명을 매개변수로 가져와서 파일을 읽고 버퍼에 데이터를 저장하여 문자열을 리턴한다.
**	반환값 : 파일 내용이 저장된 문자열 포인터를 반환한다.
*/

char	*get_dict_buf(char *dict)
{
	char	buf[BUF_SIZE];
	int		buf_len;
	int		size;
	int		fd;
	char	*dest;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		g_flag = g_flag | 0x2100;
		return (0);
	}
	size = 0;
	while ((buf_len = read(fd, buf, BUF_SIZE)))
		size += buf_len;
	close(fd);
	if (!(dest = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	dest = read_buf(dict, dest);
	dest[size] = 0;
	return (dest);
}

/*
**	int	trim_dict(char **split, int size)
**	설명 : 스플릿으로 자른 문자열에 trim을 적용하여 값 앞뒤에 있는 공백을 제거한다.
**	반환값 : 앞 뒤 공백이 제대로 제거 됬다면 1을 반환, 아니면 할당된 메모리를 해제하고 0을 반환한다.
*/

int		trim_dict(char **split, int size)
{
	int		i;
	char	*temp;

	i = 0 - 1;
	while (++i < size)
	{
		if (!(temp = ft_trim(split[i])))
			return (0);
		free(split[i]);
		if (!(split[i] = ft_strdup(temp, 0, ft_strlen(temp))))
		{
			free_dict_split(split, size);
			free(temp);
			return (0);
		}
		free(temp);
	}
	return (1);
}

/*
**	int	key_val_init(char *str, int num, t_dict *dict)
**	설명 : 문자열에서 key 값과, value 값을 추출하고, 그것을 딕셔너리 구조체에 저장한다.
**	반환값 : 제대로 데이터가 할당된 경우 1을 반환, 아닌 경우 0을 반환한다.
*/

int		key_val_init(char *str, int num, t_dict *dict)
{
	int		st;
	int		en;
	char	*temp;

	st = 0;
	en = st;
	while (str[en] && str[en] != ':')
		en++;
	if (!(temp = ft_strdup(str, st, en)))
		return (0);
	dict->key[num] = ft_trim(temp);
	free(temp);
	st = en + 1;
	en = st;
	while (str[en])
		en++;
	if (!(temp = ft_strdup(str, st, en)))
		return (0);
	dict->value[num] = ft_trim(temp);
	free(temp);
	return (1);
}

/*
**	t_dict	*dict_init(char **split, int dict_size)
**	설명 : 딕셔너리 구조체 포인터에 메모리를 할당한다.
**	반환값 : 딕셔너리 포인터를 반환한다.
**	g_flag와 0x10을 or 연산한여 t_dict에 메모리가 제대로 할당됬는지 아닌지에 대한 상태를 저장한다.
**	g_flag와 0x20을 or 연산하여	t_dict key에 메모리가 제대로 할당됬는지 아닌지에 대한 상태를 저장한다.
**	g_flag와 0x40을 or 연산하여	t_dict value에 메모리가 제대로 할당됬는지 아닌지에 대한 상태를 저장한다.
**	g_flag와 0x80을 or 연산하여	구조체에 값이 제대로 할당 됬는지 아닌지에 대한 상태를 저장한다.
*/

t_dict	*dict_init(char **split, int dict_size)
{
	t_dict	*new_dict;
	int		i;

	if (!(new_dict = (t_dict *)malloc(sizeof(t_dict) * 1)))
	{
		g_flag |= 0x10;
		return (0);
	}
	new_dict->size = dict_size;
	if (!(new_dict->key = (char **)malloc(sizeof(char *) * dict_size)))
	{
		g_flag |= 0x20;
		return (0);
	}
	if (!(new_dict->value = (char **)malloc(sizeof(char *) * dict_size)))
	{
		g_flag |= 0x40;
		return (0);
	}
	i = 0 - 1;
	while (++i < dict_size)
		if (!(key_val_init(split[i], i, new_dict)))
			g_flag |= 0x80;
	return (new_dict);
}
