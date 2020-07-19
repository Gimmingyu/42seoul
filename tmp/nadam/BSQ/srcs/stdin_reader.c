/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:50:00 by jko               #+#    #+#             */
/*   Updated: 2020/02/12 23:50:04 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "map_reader.h"

char		**read_from_stdin(int size)
{
	char	**lines;
	char	*line;
	int		len;
	char	buf[1];

	if (size <= 0)
		return (0);
	line = 0;
	len = 0;
	while (size > 0 && (len = read(0, buf, 1)))
	{
		line = ft_strdup_and_strcat(line, buf, len);
		if (buf[0] == '\n')
		{
			size--;
			line = ft_strdup_and_strcat(line, "\t", 1);
		}
	}
	if (line == 0)
		return (0);
	lines = ft_split(line, "\t");
	free(line);
	return (lines);
}

t_map_info	*read_map_info_from_stdin(char *void_param)
{
	t_map_info	*map_info;
	char		**lines;
	char		**line;

	void_param++;
	if ((line = read_from_stdin(1)) == 0)
		return (0);
	map_info = parse_map_info(line[0]);
	free_strs(line, 0);
	if (map_info == 0)
		return (0);
	if ((lines = read_from_stdin(map_info->line_num)) == 0)
	{
		free(map_info);
		return (0);
	}
	if ((map_info->map = get_map(lines)) == 0)
	{
		free_map_info(map_info);
		free_strs(lines, 0);
		return (0);
	}
	free(lines);
	return (map_info);
}
