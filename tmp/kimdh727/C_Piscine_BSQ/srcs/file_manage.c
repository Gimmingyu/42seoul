/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 00:38:09 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/13 19:40:28 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_str_to_str(char *str, char **dst, int st, int en)
{
	int i;

	i = 0 - 1;
	while (++i < en - st)
	{
		dst[0][st + i] = str[i];
	}
}

char	*make_buf(int fd)
{
	char	buf[4096];
	char	*dest;
	char	*temp;
	int		size;
	int		len;

	size = 1;
	if (!(dest = (char *)malloc(sizeof(char) * 1)))
		return (0);
	if (!(temp = (char *)malloc(sizeof(char) * 1)))
		return (0);
	while ((len = read(fd, &buf, 4096)) && dest && temp)
	{
		free(dest);
		dest = ft_strdup(temp, 0, (size - 1) * 4096 + 1, size * 4096 + 1);
		ft_str_to_str(buf, &dest, (size - 1) * 4096, (size - 1) * 4096 + len);
		dest[(size - 1) * 4096 + len] = 0;
		free(temp);
		temp = ft_strdup(dest, 0, (size - 1) * 4096 + len, size * 4096 + 1);
		if (buf[len] == 0)
			break ;
		size++;
	}
	free(temp);
	return (dest);
}

int		check_info(char *info)
{
	int		len;
	char	*row_data;
	int		row;

	len = ft_strlen(info);
	if (!(row_data = ft_strdup(info, 0, len - 3, len - 3)))
		return (0);
	if (!(row = ft_atoi(row_data)))
	{
		free(row_data);
		return (0);
	}
	free(row_data);
	if (!((info[len - 1] != info[len - 2]) &&
		(info[len - 2] != info[len - 3]) &&
		(info[len - 3] != info[len - 1])))
		return (0);
	return (row);
}

char	**read_map(char *buf)
{
	char	**map_file;
	int		row;
	int		col;

	if (buf == 0)
		return (0);
	if (!(empty_line_check(buf)))
	{
		free(buf);
		return (0);
	}
	map_file = ft_split(buf, "\n");
	if (map_file)
	{
		row = check_info(map_file[0]);
		col = same_row_len(map_file, row);
		if (print_able_map(map_file) && row && col)
		{
			free(buf);
			return (map_file);
		}
	}
	free_split(ft_strarrlen(map_file), map_file);
	free(buf);
	return (0);
}
