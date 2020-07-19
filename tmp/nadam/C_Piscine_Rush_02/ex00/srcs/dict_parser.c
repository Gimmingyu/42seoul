/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:12:13 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 20:51:28 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

int		get_len_space_end(char *str, int start)
{
	int len;

	len = 0;
	while (str[start + len]
			&& str[start + len] != ' ' && str[start + len] != ':')
	{
		if (str[start + len] < '0' || str[start + len] > '9')
			return (-1);
		len++;
	}
	return (len);
}

int		get_len_newline_end(char *str, int start)
{
	int len;

	len = 0;
	while (str[start + len] && str[start + len] != '\n')
		len++;
	return (len);
}

int		pass_whitespace(char *str, int start)
{
	while (str[start] && str[start] == ' ')
		start++;
	return (start);
}

int		pass_whitespace_and_colon(char *str, int start)
{
	int i;

	i = pass_whitespace(str, start);
	if (str[i++] != ':')
		return (0);
	i = pass_whitespace(str, i);
	return (i);
}

char	**parse_line(char *str)
{
	char	**result;
	int		i;

	result = (char **)malloc(sizeof(char *) * 2);
	if (result == 0)
		return (0);
	i = pass_whitespace(str, 0);
	result[0] = ft_strdup(str, i, get_len_space_end(str, i));
	if (result[0] == 0)
	{
		free(result);
		return (0);
	}
	i += get_len_space_end(str, i);
	if ((i = pass_whitespace_and_colon(str, i)) == 0)
	{
		free_strs(result, 1);
		return (0);
	}
	result[1] = ft_strdup(str, i, get_len_newline_end(str, i));
	if (result[1] != 0)
		return (result);
	free_strs(result, 2);
	return (0);
}
