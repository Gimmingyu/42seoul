/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_manage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:45:16 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/09 20:27:55 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdlib.h>

/*
**	void	free_key(t_dict *dict)
**	설명 : 딕셔너리 구조체에 할당된 key 메모리를 해제한다.
**	반환값 : 없음
*/

void	free_key(t_dict *dict)
{
	int i;

	i = 0 - 1;
	while (++i < dict->size)
		free(dict->key[i]);
	free(dict->key);
}

/*
**	void	free_value(t_dict *dict)
**	설명 : 딕셔너리 구조체에 할당된 value 메모리를 해제한다.
**	반환값 : 없음
*/

void	free_value(t_dict *dict)
{
	int i;

	i = 0 - 1;
	while (++i < dict->size)
		free(dict->value[i]);
	free(dict->value);
}

/*
**	void	free_dict(t_dict *dict)
**	설명 : 메모리가 할당 해제 되어있는지를 비트로 확인한다.
**	g_flag가 01 인 경우 모든 메모리 해제 상태
**	g_flag와 10 를 and 하였는데 0이면 key 메모리 할당이 해제 되지 않은 상태
**	g_flag와 4를 and 하였는데 0이면 value 메모리 할당이 해제 되지 않은 상태
**	반환값 : 없음
*/

void	free_dict(t_dict *dict)
{
	if (g_flag & 0x10)
		return ;
	if (!(g_flag & 0x20))
		free_key(dict);
	if (!(g_flag & 0x40))
		free_value(dict);
	free(dict);
}

/*
**	void	free_dict_split(char **split, int size)
**	설명 : 스플릿 함수로 나눈 문자열의 동적 메모리를 해제한다.
**	반환값 : 없음
*/

void	free_dict_split(char **split, int size)
{
	int i;

	i = 0 - 1;
	while (++i < size)
	{
		free(split[i]);
	}
	free(split);
}
