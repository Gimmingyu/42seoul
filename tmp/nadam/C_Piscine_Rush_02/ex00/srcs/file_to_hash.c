/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 14:53:03 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 20:15:43 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "hash.h"
#include "read_file.h"
#include "dict_parser.h"
#include "ft_string.h"
#include "file_to_hash.h"

char	is_empty_line(char *str)
{
	if (str[0] && str[0] != '\n')
		return (0);
	return (1);
}

int		parse_and_put_dict(t_dict **hash, char **lines)
{
	t_dict	*new_dict;
	char	**key_and_value;
	int		i;

	i = -1;
	while (lines[++i])
	{
		if (is_empty_line(lines[i]))
			continue ;
		key_and_value = parse_line(lines[i]);
		if (key_and_value == 0)
			return (0);
		new_dict = make_dict(key_and_value[0], key_and_value[1]);
		if (new_dict == 0 || put_dict(hash, new_dict) == 0)
		{
			free_strs(key_and_value, 2);
			if (new_dict != 0)
				free_dict(new_dict);
			return (0);
		}
	}
	return (1);
}

t_dict	**read_file_and_make_hash(char *file_name)
{
	t_dict	**hash;
	char	**lines;

	hash = init_hash();
	if (hash == 0)
		return (0);
	lines = read_dict_file(file_name);
	if (lines == 0)
	{
		free_hash(hash);
		return (0);
	}
	if (!parse_and_put_dict(hash, lines))
	{
		free_strs(lines, -1);
		free_hash(hash);
		return (0);
	}
	free_strs(lines, -1);
	return (hash);
}

t_dict	**change_dict_file(char *file_name, t_dict **hash)
{
	free_hash(hash);
	return (read_file_and_make_hash(file_name));
}
