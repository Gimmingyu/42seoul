/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:55:39 by jipark            #+#    #+#             */
/*   Updated: 2020/02/09 22:26:19 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

/*
**	[print_*] function is aimed to display appropriate numbers
**	acccording to decimal digits.
*/

void	print_one(char *str)
{
	char	*temp;
	int		i;

	temp = ft_strdup(str, 0, 1);
	i = 0 - 1;
	while (++i < g_map.size)
	{
		if (!(ft_strcmp(temp, g_map.key[i])))
		{
			if (!g_flag || temp[0] != '0')
				ft_putstr(g_map.value[i]);
			free(temp);
			g_flag = 1;
			return ;
		}
	}
}

void	print_ten(char *str)
{
	char	*temp;
	int		i;

	if (str[0] == '0')
	{
		print_one(str + 1);
		return ;
	}
	temp = ft_strdup(str, 0, 2);
	i = 0 - 1;
	while (++i < g_map.size)
	{
		if (!(ft_strcmp(temp, g_map.key[i])))
		{
			ft_putstr(g_map.value[i]);
			free(temp);
			g_flag = 1;
			return ;
		}
	}
	temp[1] = '0';
	print_ten(temp);
	print_one(str + 1);
	free(temp);
}

void	print_hundread(char *str)
{
	int		i;
	char	*temp;

	if (str[0] == '0')
	{
		print_ten(str + 1);
		return ;
	}
	i = 0 - 1;
	temp = make_digit(3);
	while (++i < g_map.size)
	{
		if (!(ft_strcmp(temp, g_map.key[i])))
		{
			print_one(str);
			ft_putstr(g_map.value[i]);
			free(temp);
			print_ten(str + 1);
			return ;
		}
	}
}

void	print_num(char *value, int ref)
{
	if (ref == 1)
		print_one(value);
	else if (ref == 2)
		print_ten(value);
	else if (ref == 3)
		print_hundread(value);
}

/*
**	[print_digit] function is aimed to display base number
**	with appropriate digits.
*/

void	print_digit(int ref)
{
	int		i;
	char	*digit;

	digit = make_digit(ref * 3 + 1);
	i = -1;
	while (++i < g_map.size)
	{
		if (!(ft_strcmp(digit, g_map.key[i])))
		{
			ft_putstr(g_map.value[i]);
			free(digit);
			return ;
		}
	}
}
