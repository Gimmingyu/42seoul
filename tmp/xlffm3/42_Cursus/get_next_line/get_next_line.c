/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:07:15 by jipark            #+#    #+#             */
/*   Updated: 2020/04/07 17:49:03 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_new_idx(char *buf, int res)
{
	int i;

	i = 0;
	while (i < res && buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		append_new_line(char **line, char *buf, int idx)
{
	char *dup_str;

	if (!(dup_str = ft_strdup(buf, 0, idx)))
		return (0);
	if (!(*line = ft_strjoin(*line, dup_str)))
	{
		free(dup_str);
		return (0);
	}
	free(dup_str);
	return (1);
}

int		get_idx(char **line, char *buf, int res)
{
	int idx;

	if (res < 0)
		res = BUFFER_SIZE;
	if ((idx = check_new_idx(buf, res)) < 0)
	{
		if (!(*line = ft_strjoin(*line, buf)))
			return (-2);
		buf[BUFFER_SIZE + 1] = 0;
	}
	else
	{
		if (!(append_new_line(line, buf, idx)))
			return (-2);
		buf[BUFFER_SIZE + 1] = 1;
		return (idx);
	}
	return (-1);
}

int		check_validation(char **line, char *tmp[], int *res, int fd)
{
	if (read(fd, NULL, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	*line = 0;
	*res = 1;
	if (!tmp[fd])
	{
		if (!(tmp[fd] = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 2))))
			return (0);
		tmp[fd][BUFFER_SIZE + 1] = 0;
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char *tmp[FD_SIZE];
	char		buf[BUFFER_SIZE + 2];
	int			res;
	int			idx;

	idx = 0;
	if (line == NULL || !check_validation(line, tmp, &res, fd))
		return (get_return(-3, fd, line, tmp));
	if (tmp[fd][BUFFER_SIZE + 1] && ((idx = get_idx(line, tmp[fd], -1)) >= 0))
		ft_bufcpy(tmp[fd], tmp[fd], idx + 1);
	else if (idx == -2)
		return (get_return(-2, fd, line, tmp));
	while (!tmp[fd][BUFFER_SIZE + 1] && (res = read(fd, &buf, BUFFER_SIZE)))
	{
		buf[res] = '\0';
		if ((idx = get_idx(line, buf, res)) >= 0)
		{
			ft_bufcpy(tmp[fd], buf, idx + 1);
			tmp[fd][BUFFER_SIZE + 1] = 1;
		}
		else if (idx == -2)
			return (get_return(-2, fd, line, tmp));
	}
	return (get_return(res, fd, line, tmp));
}
