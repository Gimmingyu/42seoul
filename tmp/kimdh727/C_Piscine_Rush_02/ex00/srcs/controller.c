/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 01:32:37 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/09 20:22:59 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

/*
**		int		is_num(char c)
**		설명 : 한 문자를 입력받아 0~9인 문자인지 조건 확인.
** 		반환값 : 0~9 이면 1을 리턴, 아니면 0을 리턴.
*/

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
** 		int		is_printable(char c)
**		설명 : 아스키 코드의 출력 가능한 범위 문자인지 조건 확인.
**		반환값 : 출력 가능한 범위 문자이면 리턴 1, 아니면 0을 리턴.
*/

int		is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*
**		is_space(char c)
**		설명 :  아스키 코드 공백 문자(화이트 스페이스)
**		반환값 : 공백 문자가 있으면 반환값 1, 아니면 0을 리턴!
*/

int		is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

/*
**	int	is_key(char *str)
**	state = 0 : start
**	state = 1 : processing
**	설명 : 문자열 str이 숫자인지 아닌지 판단한다.
**	반환값 : 숫자로 이루어져 있는 문자열이면 1 아니면 0을 반환한다.
*/

int		is_key(char *str)
{
	int i;
	int state;

	state = 0;
	if (str[0] == '0' && str[1] == 0)
		state = 1;
	i = 0 - 1;
	while (str[++i])
	{
		if (state == 0 && str[i] >= '1' && str[i] <= '9')
			state = 1;
		else if (state == 1 && is_num(str[i]))
			continue ;
		else
			return (0);
	}
	if (i > 39)
		return (0);
	return (1);
}

/*
**	int	is_value(char *str)
**	설명 : 문자열 str을 받아서 출력 가능한지 아닌지 판단한다.
**	반환값 : 출력 가능한 문자열이면 1, 아니면 0을 반환한다.
*/

int		is_value(char *str)
{
	int i;

	i = 0 - 1;
	while (str[++i])
		if (!is_printable(str[i]))
			return (0);
	return (1);
}
