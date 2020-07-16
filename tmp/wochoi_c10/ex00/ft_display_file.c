/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochoi <wochoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 12:28:50 by wochoi            #+#    #+#             */
/*   Updated: 2020/07/14 12:58:16 by wochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#define NO_ARG_MSG "File name missing.\n"
#define NO_ARG_MSIZE 19
#define MANY_ARG_MSG "Too many arguments.\n"
#define MANY_ARG_MSIZE 20
#define CANNOT_READ_MSG "Cannot read file.\n"
#define CANNOT_READ_MSIZE 18
#define BUFF_SIZE 64

int			main(int argc, char **argv)
{
	char	buff[BUFF_SIZE];
	int		fd;
	int		len;

	if (argc == 1)
		write(1, NO_ARG_MSG, NO_ARG_MSIZE);
	else if (argc > 2)
		write(1, MANY_ARG_MSG, MANY_ARG_MSIZE);
	else if ((fd = open(argv[1], O_RDONLY)) == -1)
		write(1, CANNOT_READ_MSG, CANNOT_READ_MSIZE);
	else
	{
		while ((len = read(fd, buff, BUFF_SIZE)) > 0)
		{
			write(1, buff, len);
		}
		close(fd);
		if (len < 0)
			return (1);
	}
	return (0);
}
