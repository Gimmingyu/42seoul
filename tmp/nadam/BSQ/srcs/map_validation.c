/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:08:39 by jko               #+#    #+#             */
/*   Updated: 2020/02/11 16:06:57 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_reader.h"
#include "ft_string.h"

char	check_len(char **map, int line_num)
{
	int len;
	int i;

	if (line_num < 1)
		return (0);
	len = ft_strlen(map[0]);
	if (len < 1)
		return (0);
	i = 1;
	while (map[i] && i < line_num)
	{
		if (len != ft_strlen(map[i]))
			return (0);
		i++;
	}
	if (i != line_num)
		return (0);
	return (1);
}

char	check_chars(t_map_info *info)
{
	if (info->blank < 32 || info->blank > 126)
		return (0);
	if (info->obs < 32 || info->obs > 126)
		return (0);
	if (info->mark < 32 || info->mark > 126)
		return (0);
	if (info->blank == info->obs
			|| info->blank == info->mark
			|| info->obs == info->mark)
		return (0);
	return (1);
}

char	is_map_char(t_map_info *info, char c)
{
	if (info->blank == c)
		return (1);
	if (info->obs == c)
		return (1);
	return (0);
}

char	check_only_chars(t_map_info *info)
{
	int i;
	int j;

	i = 0;
	while ((info->map)[i] && i < info->line_num)
	{
		j = 0;
		while ((info->map)[i][j])
		{
			if (!is_map_char(info, (info->map)[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	is_valid_map(t_map_info *info)
{
	if (check_len(info->map, info->line_num) == 0)
		return (0);
	if (check_chars(info) == 0)
		return (0);
	if (check_only_chars(info) == 0)
		return (0);
	return (1);
}
