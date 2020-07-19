/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 17:31:04 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/09 20:21:46 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/*
**	void	ft_swap(char *a, char *b)
**	설명 : 문자 포인터를 받아서 a와 b를 교체한다.
*/

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
**	void	space_process(char *str)
**	설명 : 문자열을 탐색해서 여러개의 공백을 하나로 압축합니다.
*/

void	space_process(char *str)
{
	int		idx;
	int		st;
	int		en;

	idx = 0 - 1;
	while (str[++idx])
	{
		if (str[idx] == ' ')
		{
			st = idx + 1;
			en = idx;
			while (str[en] == ' ')
				en++;
			str[st - 1] = ' ';
			while (str[en])
				str[st++] = str[en++];
			str[st] = 0;
		}
	}
}

/*
**	int	key_check(t_dict *dict)
**	설명 : 정상적으로 t 구조체 배열에 키가 들어갔는지 아닌지를 체크합니다.
**	정상적으로 들어가지 않았으면 dict error 또는 자료 에러로 간주하고 g_flag 384를 곱합니다.
**	반환값 : 체크 후 구조체가 정상적이면 1, 아니면 0을 리턴합니다.
*/

int		key_check(t_dict *dict)
{
	int		i;

	i = 0 - 1;
	while (++i < dict->size)
	{
		if (!(is_key(dict->key[i])) || !(dict->key[i]))
		{
			g_flag |= 0x180;
			return (0);
		}
	}
	return (1);
}

/*
**	int	value_check(t_dict *dict)
**	설명 : 정상적으로 t 구조체 배열에 value가 들어갔는지 아닌지를 체크합니다.
**	정상적으로 들어가지 않았으면 dict error 또는 자료 에러로 간주하고 g_flag 384를 곱합니다.
**	반환값 : 체크 후 구조체가 정상적이면 1, 아니면 0을 리턴합니다.
*/

int		value_check(t_dict *dict)
{
	int		i;

	i = 0 - 1;
	while (++i < dict->size)
	{
		if (!(is_value(dict->value[i])) || !(dict->value[i]))
		{
			g_flag |= 0x180;
			return (0);
		}
		space_process(dict->value[i]);
	}
	return (1);
}

/*
**	int	dict_check(t_dict *dict)
**	설명 : 딕셔너리 구조체에 키와 값이 정상적인지 체크합니다.
**	반환값 : 정상적이면 1을 반환하고 아니면 메모리를 해제하고 0을 반환합니다.
*/

int		dict_check(t_dict *dict)
{
	if (!(key_check(dict)))
	{
		free_dict(dict);
		return (0);
	}
	if (!(value_check(dict)))
	{
		free_dict(dict);
		return (0);
	}
	return (1);
}
