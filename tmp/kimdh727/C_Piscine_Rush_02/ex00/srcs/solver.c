/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 19:44:33 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/09 21:40:05 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <stdlib.h>
#include <unistd.h>

/*
**	t_dict	*get_dict(char *dict)
**	설명 : dict문자열을 출력 받아서 가공한다.
**	반환값 : 제대로 가공됬으면 t_dict 구조체 포인터를 반환하고, 아니면 널 포인터를 반환한다.
*/

t_dict	*get_dict(char *dict)
{
	char	*dict_buf;
	char	**dict_split;
	int		dict_size;
	t_dict	*dictonary;

	if (!(dict_buf = get_dict_buf(dict)))
		return (0);
	if (!(dict_split = ft_split(dict_buf, (char *)"\n")))
		return (0);
	free(dict_buf);
	dict_size = 0;
	while (dict_split[dict_size])
		dict_size++;
	if (!(trim_dict(dict_split, dict_size)))
		return (0);
	if (!(dictonary = dict_init(dict_split, dict_size)))
	{
		free_dict(dictonary);
		free_dict_split(dict_split, dict_size);
		return (0);
	}
	free_dict_split(dict_split, dict_size);
	return (dictonary);
}

/*
**	char	*make_digit(int digit)
**	설명 : 매개변수 digit을 받아서 앞은 1 나머지는 0인 문자열을 만듭니다
**	반환값 : 문자열 포인터를 반환합니다.
*/

char	*make_digit(int digit)
{
	char	*dest;
	int		i;

	dest = (char *)malloc(sizeof(char) * digit + 1);
	dest[0] = '1';
	i = 1 - 1;
	while (++i < digit)
		dest[i] = '0';
	dest[i] = 0;
	return (dest);
}

/*
**	void	get_solution(char *value, t_dict *dict)
**	설명: value값을 로직을 사용하여 적절히 출력합니다.
**	반환값 : solver에 값이 복사되지 않는경우 (널문자)이면 함수를 종료합니다.
*/

void	get_solution(char *value, t_dict *dict)
{
	int		st;
	int		en;
	int		ref;
	char	*solver;

	st = 0;
	en = ft_strlen(value);
	ref = (en - 1) / 3;
	en = st + (en - 1) % 3 + 1;
	while (ref >= 0)
	{
		if (!(solver = ft_strdup(value, st, en)))
			return ;
		print_num(solver, en - st, dict);
		if (ref && ft_strcmp(solver, (char *)"000"))
			print_digit(ref, dict);
		st = en;
		en = en + 3;
		ref--;
		free(solver);
	}
	write(1, "\n", 1);
}
