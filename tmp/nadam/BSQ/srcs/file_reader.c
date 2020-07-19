/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:25:10 by jko               #+#    #+#             */
/*   Updated: 2020/02/12 18:42:00 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		get_line_num(char *file_name)
{
	int		fd;
	int		n;
	int		len;
	char	buf[1];

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (-1);
	len = 0;
	while ((n = read(fd, buf, 1)))
	{
		if (buf[0] == '\n')
			len++;
	}
	close(fd);
	return (len);
}

int		get_next_line_length(int fd)
{
	int		len;
	char	buf[1];

	if (fd < 0)
		return (0);
	len = 0;
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
			return (len + 1);
		len++;
	}
	return (len);
}

char	*get_next_line(int fd, int length)
{
	char	*result;

	if (fd < 0 || length <= 0)
		return (0);
	result = (char *)malloc(sizeof(char) * length);
	if (result == 0)
		return (0);
	if (read(fd, result, length) != length)
	{
		free(result);
		return (0);
	}
	result[length - 1] = 0;
	return (result);
}

char	**read_lines(int fd1, int fd2, int line_num, char **result)
{
	int		line_len;
	int		i;
	int		j;

	i = 0;
	while (i < line_num)
	{
		line_len = get_next_line_length(fd1);
		if ((result[i] = get_next_line(fd2, line_len)) == 0)
		{
			j = 0;
			while (j < i)
				free(result + j++);
			return (0);
		}
		i++;
	}
	result[i] = 0;
	return (result);
}

char	**read_file(char *file_name)
{
	int		fd1;
	int		fd2;
	int		line_num;
	char	**result;

	line_num = get_line_num(file_name);
	if (line_num < 0)
		return (0);
	result = (char **)malloc(sizeof(char *) * (line_num + 1));
	if (result == 0)
		return (0);
	fd1 = open(file_name, O_RDONLY);
	fd2 = open(file_name, O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		close(fd1);
		close(fd2);
		return (0);
	}
	if (read_lines(fd1, fd2, line_num, result) == 0)
		free(result);
	close(fd1);
	close(fd2);
	return (result);
}
