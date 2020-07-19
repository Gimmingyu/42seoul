/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 13:40:37 by donghwki          #+#    #+#             */
/*   Updated: 2020/05/01 23:27:46 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"
#include <unistd.h>
#include <stdlib.h>

/*
**	void	print_one(char *str, t_dict *dict)
**	설명 :	문자열을 받아서 1의 자리 key값과 일치하는 1의 자리 value를 줄력한다.
**	반환값 : 없음
*/

void	print_one(char *str, t_dict *dict)
{
	int		i;
	char	*temp;

	temp = ft_strdup(str, 0, 1);
	i = 0 - 1;
	while (++i < dict->size)
	{
		if (!(ft_strcmp(temp, dict->key[i])))
		{
			if (!g_flag || temp[0] != '0')
			{
				if (g_flag & 0x1)
					write(1, " ", 1);
				ft_putstr(dict->value[i]);
				g_flag |= 0x1;
			}
			free(temp);
			return ;
		}
	}
}

/*
**	void	print_ten(char *str, t_dict *dict)
**	설명 :	문자열을 받아서 10의 자리 key값과 일치하는 10의 자리 value를 줄력한다.
**	반환값 : 없음
*/

void	print_ten(char *str, t_dict *dict, char split)
{
	int		i;
	char	*temp;

	if (str[0] == '0')
	{
		print_one(str + 1, dict);
		return ;
	}
	i = 0 - 1;
	while (++i < dict->size)
	{
		if (!(ft_strcmp(str, dict->key[i])))
		{
			if (g_flag & 0x1)
				write(1, &split, 1);
			ft_putstr(dict->value[i]);
			g_flag |= 0x1;
			return ;
		}
	}
	temp = ft_strdup(str, 0, 2);
	temp[1] = '0';
	print_ten(temp, dict, ' ');
	print_one(str + 1, dict);
	free(temp);
}

/*
**	void	print_ten(char *str, t_dict *dict)
**	설명 :	문자열을 받아서 100의 자리 key값과 일치하는 100의 자리 value를 줄력한다.
**	반환값 : 없음
*/

void	print_hundread(char *str, t_dict *dict)
{
	int		i;
	char	*temp;

	if (str[0] == '0')
	{
		print_ten(str + 1, dict, ' ');
		return ;
	}
	i = 0 - 1;
	temp = make_digit(3);
	while (++i < dict->size)
	{
		if (!(ft_strcmp(temp, dict->key[i])))
		{
			print_one(str, dict);
			if (g_flag & 0x1)
				write(1, " ", 1);
			ft_putstr(dict->value[i]);
			g_flag |= 0x1;
			free(temp);
			print_ten(str + 1, dict, ' ');
			return ;
		}
	}
}

/*
**	void	print_num(char *value, int ref, t_dict *dict)
**	설명 : ref를 사용하여 그에 맞게 1의 자리, 10의자리, 100의 자리를 출력한다.
**	반환값 : 없음
*/

void	print_num(char *value, int ref, t_dict *dict)
{
	if (ref == 1)
		print_one(value, dict);
	else if (ref == 2)
		print_ten(value, dict, ' ');
	else if (ref == 3)
		print_hundread(value, dict);
}

/*
**	void	print_digit(int ref, t_dict *dict)
**	설명 : ref를 사용하여 자리 수를 파악하고, 그에 맞는 자리를 출력한다.
**	반환값 : 없음
*/

void	print_digit(int ref, t_dict *dict)
{
	int		i;
	char	*digit;

	digit = make_digit(ref * 3 + 1);
	i = 0 - 1;
	while (++i < dict->size)
	{
		if (!(ft_strcmp(digit, dict->key[i])))
		{
			if (g_flag & 0x1)
				write(1, " ", 1);
			ft_putstr(dict->value[i]);
			g_flag |= 0x1;
			free(digit);
			return ;
		}
	}
}
