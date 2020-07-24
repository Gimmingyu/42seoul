/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 03:43:25 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/23 08:27:59 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char		*get_info(char *filename)
{
	char	buf[BUF_SIZE];
	ssize_t rd_size;
	int		cnt;
	char	*data;
	int		file;

	if ((file = open(filename, O_RDONLY)) < 0)
	{
		print_error();
		return (0);
	}
	cnt = 0;
	while ((rd_size = read(file, buf, sizeof(buf))) > 0)
	{
		while (buf[cnt++])
			if (buf[cnt] == '\n')
				break ;
		if (cnt > 0)
			break ;
	}
	data = (char *)malloc(sizeof(char) * cnt);
	data = cpy_str_except_newline(buf, data);
	close(file);
	return (data);
}

int			get_x_len(int file)
{
	int		size;
	char	buff[BUF_SIZE];
	int		i;
	int		count;
	int		flag;

	flag = 0;
	count = 0;
	size = read(file, buff, sizeof(buff));
	if (size > 0)
	{
		i = 0;
		while (i < BUF_SIZE)
		{
			if (buff[i++] == '\n')
				flag++;
			if (flag == 1)
				count++;
			if (flag == 2)
				break ;
		}
	}
	close(file);
	return (count - 1);
}

t_map		set_info(char *str)
{
	t_map info;

	info.y = 0;
	while (*str >= '0' && *str <= '9')
	{
		info.y = info.y * 10 + *str - '0';
		str++;
	}
	info.empty = *str++;
	info.obst = *str++;
	info.full = *str;
	return (info);
}

t_map		file_to_struct(char *filename)
{
	char	*data;
	int		len;
	int		file;
	t_map	info;

	data = get_info(filename);
	len = ft_strlen(data);
	info = set_info(data);
	file = open(filename, O_RDONLY);
	if (file < 0)
	{
		print_error();
		return (info);
	}
	info.x = get_x_len(file);
	if (0 > (file = open(filename, O_RDONLY)))
		return (info);
	data = malloc(sizeof(char) * (len + 1));
	read(file, data, len + 1);
	info = set_map(file, info);
	return (info);
}

t_map		set_map(int file, t_map info)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buff = malloc(sizeof(char) * (info.x + 1));
	info.map = malloc(sizeof(int *) * info.y);
	while (0 < read(file, buff, info.x + 1))
	{
		info.map[i] = malloc(sizeof(int) * info.x);
		while (buff[j] != '\n')
		{
			if (buff[j] == info.empty)
				info.map[i][j] = 1;
			else if (buff[j] == info.obst)
				info.map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (info);
}
