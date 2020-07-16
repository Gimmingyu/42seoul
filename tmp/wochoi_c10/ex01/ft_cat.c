/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochoi <wochoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:34:13 by wochoi            #+#    #+#             */
/*   Updated: 2020/07/14 22:12:01 by wochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

#define BUFF_SIZE 64

void		print(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		++len;
	write(1, str, len);
}

int			cat_w_file(char *program, char *file)
{
	int		fd;
	int		len;
	char	buff[BUFF_SIZE];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		print(basename(program));
		print(": ");
		print(file);
		print(": ");
		print(strerror(errno));
		print("\n");
		return (0);
	}
	while ((len = read(fd, buff, BUFF_SIZE)) > 0)
		write(1, buff, len);
	close(fd);
	if (len < 0)
	{
		print(strerror(errno));
		return (1);
	}
	return (0);
}

void		cat_wo_file(void)
{
	char	c;

	while (read(0, &c, 1) > 0)
	{
		write(1, &c, 1);
	}
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		cat_wo_file();
	else
	{
		i = 1;
		while (i < argc)
		{
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				cat_wo_file();
			else if (cat_w_file(argv[0], argv[i++]))
				return (1);
		}
	}
	return (0);
}
