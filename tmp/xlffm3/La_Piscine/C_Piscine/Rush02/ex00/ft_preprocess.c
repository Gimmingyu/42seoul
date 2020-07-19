/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:55:59 by jipark            #+#    #+#             */
/*   Updated: 2020/02/09 22:11:41 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

/*
**	[check_valid_number] function is aimed to figure out if a key number
**	which user puts is valid. If the number formed with two or more
**	digits starts with '0', it is not valid. If the number contains
**	characters not the range of '0' to '9', it is not valid.
**	Although the function ignores white spaces, the number must be
** 	represented consecutively.
**	ex) '  0  ' is valid, but '1 3' or ' 3.1 ' is not valid.
*/

int		check_valid_number(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i++;
	if (*str == 0 || str[i] == '\0')
		return (0);
	if (str[i] == '0' && ('0' <= str[i + 1] && str[i + 1] <= '9'))
		return (0);
	while (str[i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			break ;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!(str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}

/*
**	[get_trimed_length] function is aimed to calculate the length
**	of a trimed string.
*/

int		get_trimed_length(char *str)
{
	int		i;
	int		length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
			length++;
		i++;
	}
	return (length);
}

/*
**	[get_trimed_number] function is aimed to duplicate trimed string.
**	The function returns the pointer of dynamically allocated string,
**	or NULL pointer if it fails.
*/

char	*get_trimed_number(char *str)
{
	char	*trimed_number;
	int		i;
	int		size;
	int		index;

	i = 0;
	size = get_trimed_length(str);
	if (!(trimed_number = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	i = 0;
	index = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] == ' ' || (9 <= str[i] && str[i] <= 13)))
		{
			trimed_number[index] = str[i];
			index++;
		}
		i++;
	}
	trimed_number[index] = '\0';
	return (trimed_number);
}

/*
**	[get_map_size] function is aimed to calculate the number of key-value pair
**	from dictionary which equals to the total available rows of dictionary file.
**	The function counts 1 when it encounter ':' and '\n'.
*/

int		get_map_size(char *dict_name)
{
	char	c;
	int		cnt;
	int		is_colon;

	g_file = open(dict_name, O_RDONLY);
	if (g_file < 0)
		return (0);
	cnt = 0;
	is_colon = 0;
	while (read(g_file, &c, sizeof(char)))
	{
		if (c == ':' && is_colon == 0)
			is_colon = 1;
		else if (c == '\n' && is_colon == 1)
		{
			is_colon = 0;
			cnt++;
		}
	}
	close(g_file);
	return (cnt);
}
