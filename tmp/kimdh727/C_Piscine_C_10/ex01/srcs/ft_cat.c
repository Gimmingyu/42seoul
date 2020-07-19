/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 23:50:59 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/07 02:03:26 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

// 30 ko : 30 kB = 30 * 1024

// openvt  will  find  the first available VT, and run on it the given command with
// the given command options, standard input, output and error are directed to that terminal.
// The current search path ($PATH) is used to find the requested command. If no
// command is specified then the environment variable $SHELL is used.\

void	ft_putstr(char *str)
{
	int strlen;

	strlen = 0;
	while (str[strlen])
		strlen++;
	write(1, str, strlen);
}

void	print_error(char *program, char *argv)
{
	ft_putstr(program);
	write(1, ": ", 2);
	ft_putstr(argv);
	write(1, ": ", 2);
	ft_putstr(strerror(errno));
	write(1, "\n", 1);
}

void	print_file(int fd)
{
	int		buf_size;
	char	buf[1024];

	while ((buf_size = read(fd, buf, 1024)))
		write(1, buf, buf_size);
	close(fd);
}

int	main(int argc, char *argv[])
{
	char buf[100];
	int i;
	int fd;
	i = read(0, buf, 100);
	write(1, buf, i);

	i = 1 - 1;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (!errno)
			print_file(fd);
		else
			print_error(argv[0], argv[i]);
		// read()
	}


	// for (int i=0; i<255; i++)
	// 	printf()
}
