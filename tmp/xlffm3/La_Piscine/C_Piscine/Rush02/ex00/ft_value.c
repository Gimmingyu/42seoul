/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_value.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:01:27 by jipark            #+#    #+#             */
/*   Updated: 2020/02/09 22:20:37 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

/*
**	[allocate_value_array] function will check the valid length of each value
**	before it encounters '\n'. When c equals to '\n', it will dynamically
**	allocate char * size of value_size for current index of char **.
**	When the function finds out invalid format of value, or fails to malloc,
**	it will return 0.
*/

int		allocate_value_array(char c, int *is_colon, int *index, int *value_size)
{
	if (*is_colon == 2 && !(9 <= c && c <= 13))
		*value_size += 1;
	if (*is_colon == 1 && !(c == ' ' || c == 9 || (11 <= c && c <= 13)))
	{
		*is_colon = 2;
		*value_size += 1;
	}
	if (*is_colon == 0 && c == ':')
		*is_colon = 1;
	if (c == '\n')
	{
		if (*is_colon == 0 || *is_colon == 1)
		{
			*is_colon = 0;
			return (1);
		}
		if (!(g_map.value[*index] = (char *)malloc(*value_size + 1)))
			return (0);
		*index += 1;
		*is_colon = 0;
		*value_size = 0;
	}
	return (1);
}

/*
**	[get_value_array] function is aimed to dynamically allocate char *
**	for each row of value string array from g_map. Thus, it checks
**	the valid length of each value while reading g_file.
*/

int		get_value_array(char *dict_name)
{
	char	c;
	int		is_colon;
	int		index;
	int		value_size;

	g_file = open(dict_name, O_RDONLY);
	if (g_file < 0)
		return (0);
	is_colon = 0;
	index = 0;
	value_size = 0;
	while (read(g_file, &c, sizeof(char)))
	{
		if (!allocate_value_array(c, &is_colon, &index, &value_size))
			return (0);
	}
	close(g_file);
	return (1);
}

/*
**	[fill_value] function will put c into value string arrays, terminating-NULL.
**	It will use ':', '\n', and 'white space' to determine
**	wheter current c is valid or not.
*/

void	fill_value(char c, int *is_colon, int *index, int *i)
{
	if (*is_colon == 2 && !(9 <= c && c <= 13))
	{
		g_map.value[*index][*i] = c;
		*i += 1;
	}
	if (*is_colon == 1 && !(c == ' ' || c == 9 || (11 <= c && c <= 13)))
	{
		*is_colon = 2;
		g_map.value[*index][*i] = c;
		*i += 1;
	}
	if (*is_colon == 0 && c == ':')
		*is_colon = 1;
	if (*is_colon == 2 && c == '\n')
	{
		g_map.value[*index][*i] = '\0';
		*index += 1;
		*is_colon = 0;
		*i = 0;
	}
}

/*
**	[set_value_array] function is aimed to initalize elements
**	of value string array of g_map according to dictionary.
**	It will put only valid character using pattern
**	':', 'white space', and '\n'.
*/

int		set_value_array(char *dict_name)
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
		fill_value(c, &is_colon, &index, &i);
	close(g_file);
	return (1);
}

/*
**	[trim_value_array] function is aimed to delete unexpected white spaces
**	after value.
*/

void	trim_value_array(void)
{
	int i;
	int j;
	int len;

	i = -1;
	while (++i < g_map.size)
	{
		len = ft_strlen(g_map.value[i]);
		j = len - 1;
		while (j >= 1)
		{
			if (g_map.value[i][len - 1] != ' ' &&
			!(9 <= g_map.value[i][len - 1] && g_map.value[i][len - 1] <= 13))
				break ;
			if ((g_map.value[i][j] == ' ' ||
			(9 <= g_map.value[i][j] && g_map.value[i][j] <= 13))
				&& g_map.value[i][j - 1] != ' '
				&& !(9 <= g_map.value[i][j - 1] && g_map.value[i][j - 1] <= 13))
			{
				g_map.value[i][j] = '\0';
				break ;
			}
			j--;
		}
	}
}
