/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:59:42 by jipark            #+#    #+#             */
/*   Updated: 2020/02/09 22:14:22 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

/*
**	[allocate_key_array] function will check the valid length of each key
**	before it encounters ':'. When c equals to ':', it will dynamically
**	allocate char * size of key_size for current index of char **.
**	When the function finds out invalid format of key, or fails to malloc,
**	it will return 0.
*/

int		allocate_key_array(char c, int *is_colon, int *index, int *key_size)
{
	if ((g_is_blank == 0 && *is_colon == 0 && !('0' <= c && c <= '9')))
		return (0);
	if (c == ':' && *is_colon == 0)
	{
		*is_colon = 1;
		if (!(g_map.key[*index] = (char *)malloc(*key_size + 1)))
			return (0);
		*index += 1;
		*key_size = 0;
		g_is_blank = 0;
	}
	if ((g_is_blank == 0 || g_is_blank == 1)
	&& *is_colon == 0 && ('0' <= c && c <= '9'))
	{
		*key_size += 1;
		g_is_blank = 1;
	}
	if (g_is_blank == 1 && *is_colon == 0 && !('0' <= c && c <= '9'))
		g_is_blank = 2;
	if (g_is_blank == 2 && !(c == ' ' || c == 9 || (11 <= c && c <= 13)))
		return (0);
	if (c == '\n' && *is_colon == 1)
		*is_colon = 0;
	return (1);
}

/*
**	[get_key_array] function is aimed to dynamically allocate char *
**	for each row of key string array from g_map. Thus, it checks
**	the valid length of each key while reading g_file.
**	if a row of dictionary is only '\n', the function ignores it.
*/

int		get_key_array(char *dict_name)
{
	char	c;
	int		is_colon;
	int		index;
	int		key_size;

	g_file = open(dict_name, O_RDONLY);
	if (g_file < 0)
		return (0);
	is_colon = 0;
	index = 0;
	key_size = 0;
	while (read(g_file, &c, sizeof(char)))
	{
		if (!(g_is_blank == 0 && is_colon == 0 && c == '\n'))
		{
			if (!allocate_key_array(c, &is_colon, &index, &key_size))
				return (0);
		}
	}
	g_is_blank = 0;
	close(g_file);
	return (1);
}

/*
**	[fill_key] function will put c into key string arrays, terminating-NULL.
**	It will use ':', '\n', and 'white space' to determine
**	wheter current c is valid or not.
*/

void	fill_key(char c, int *is_colon, int *index, int *i)
{
	if (*is_colon == 0 && c == '\n')
		return ;
	if (*is_colon == 0 && c == ':')
	{
		g_map.key[*index][*i] = '\0';
		*is_colon = 1;
		*index += 1;
		*i = 0;
	}
	if (*is_colon == 0 && !(c == ' ' || c == 9 || (11 <= c && c <= 13)))
	{
		g_map.key[*index][*i] = c;
		*i += 1;
	}
	if (*is_colon == 1 && c == '\n')
		*is_colon = 0;
}

/*
**	[set_key_array] function is aimed to initalize elements of key string array
**	of g_map according to dictionary. It will put only valid character using
**	pattern ':', 'white space', and '\n'.
*/

int		set_key_array(char *dict_name)
{
	char	c;
	int		i;
	int		is_colon;
	int		index;

	g_file = open(dict_name, O_RDONLY);
	if (g_file < 0)
		return (0);
	is_colon = 0;
	index = 0;
	i = 0;
	while (read(g_file, &c, sizeof(char)))
		fill_key(c, &is_colon, &index, &i);
	close(g_file);
	return (1);
}

/*
**	[check_valid_value] function is aimed to check whether value still
**	is invalid, such as '\n'.
*/

int		check_valid_value(void)
{
	int i;

	i = 0;
	while (i < g_map.size)
	{
		if (g_map.value[i][0] == '\n')
			return (0);
		i++;
	}
	return (1);
}
