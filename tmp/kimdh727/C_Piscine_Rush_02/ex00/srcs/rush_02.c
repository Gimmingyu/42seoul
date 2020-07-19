/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:04:10 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/09 21:13:11 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*
**	void	print_dict_error(void)
**	설명 : dict에러이면 Dict Error를 출력한다.
*/

void	print_dict(char *dict)
{
	int		i;
	t_dict	*dictonary;

	if (!(dictonary = get_dict(dict)))
	{
		if (!(g_flag & 0x2000))
			free_dict(dictonary);
		return ;
	}
	if (!(dict_check(dictonary)))
	{
		free_dict(dictonary);
		return ;
	}
	i = 0 - 1;
	while (++i < dictonary->size)
	{
		ft_putstr(dictonary->key[i]);
		write(1, ": ", 2);
		ft_putstr(dictonary->value[i]);
		write(1, "\n", 1);
	}
	free_dict(dictonary);
}

/*
**	void	rush_02_solve(char *dict, char *value)
**	설명 : 값이 제대로 들어가지 않았다면 예외상황을 처리하고,
**	상황을 비트연산자로 기록합니다. 값이 제대로 들어갔다면 연산을 실행합니다.
*/

void	rush_02_solve(char *dict, char *value)
{
	t_dict	*dictonary;

	if (!(dictonary = get_dict(dict)))
	{
		if (!(g_flag & 0x2000))
			free_dict(dictonary);
		return ;
	}
	if (!(dict_check(dictonary)))
	{
		free_dict(dictonary);
		return ;
	}
	if (!(value = ft_trim(value)))
	{
		g_flag |= 0x1100;
		return ;
	}
	if (is_key(value))
		get_solution(value, dictonary);
	else
		g_flag = 0x1000;
	free(value);
	free_dict(dictonary);
}

/*
**	void	rush_02(int argc, char *argv[])
**	설명 : 플래그를 초기화하고, argc가 1이면 디폴트 딕셔너리 파일을 파싱합니다.
**	argc가 2이면 딕셔너리 파일을 받아서 그 파일을 파싱합니다.
*/

void	rush_02(int argc, char *argv[])
{
	g_flag = 0;
	if (argc == 0)
		print_dict((char *)"numbers.dict");
	else if (argc == 1)
		rush_02_solve((char *)"numbers.dict", argv[0]);
	else if (argc == 2)
		rush_02_solve(argv[0], argv[1]);
	else
	{
		write(1, "Arguments Error\n", 16);
		return ;
	}
	if (g_flag & 0x180)
		write(1, "Dict Error\n", 11);
	if (g_flag & 0x1000)
		write(1, "Error\n", 6);
}
