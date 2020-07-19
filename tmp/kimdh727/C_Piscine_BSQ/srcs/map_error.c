/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 01:39:15 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/12 22:35:09 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		empty_line_check(char *buf)
{
	int	i;
	int	len;

	i = 0 - 1;
	len = ft_strlen(buf);
	while (++i < len - 1)
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
			return (0);
	}
	if (buf[i] != '\n')
		return (0);
	return (1);
}

int		same_row_len(char **map_file, int row)
{
	int	i;
	int	size;
	int	col;

	size = ft_strarrlen(map_file);
	if (size != row + 1 || size < 2)
		return (0);
	col = ft_strlen(map_file[1]);
	i = 1 - 1;
	while (++i < size)
	{
		if (ft_strlen(map_file[i]) != col)
			return (0);
	}
	return (col);
}

int		print_able_map(char **map_file)
{
	int		i;
	int		size;
	char	empty;
	char	obstacle;

	size = ft_strarrlen(map_file);
	if (!is_printable(map_file[0]))
		return (0);
	i = ft_strlen(map_file[0]);
	empty = map_file[0][i - 3];
	obstacle = map_file[0][i - 2];
	i = 1 - 1;
	while (++i < size)
	{
		if (!is_map(map_file[i], empty, obstacle))
			return (0);
	}
	return (1);
}
