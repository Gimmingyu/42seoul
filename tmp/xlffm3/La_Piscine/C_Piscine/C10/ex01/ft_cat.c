/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 11:39:55 by jipark            #+#    #+#             */
/*   Updated: 2020/02/07 14:11:40 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char *msg)
{
	while (*msg)
		write(1, msg++, 1);
}

void	get_input(void)
{
	char	c;

	while (read(0, &c, sizeof(char)))
		write(1, &c, 1);
}

void	print_file(int file)
{
	char c;

	while (read(file, &c, 1))
		write(1, &c, 1);
}

void	execute_cat(int argc, char *argv[])
{
	int	file;
	int	i;

	i = 1;
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file < 0)
		{
			if (errno == 2)
			{
				ft_putstr(basename(argv[0]));
				ft_putstr(": ");
				ft_putstr(argv[i]);
				ft_putstr(": ");
			}
			ft_putstr(strerror(errno));
			write(1, "\n", 1);
		}
		else
			print_file(file);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc <= 1 || (argv[1][0] == '-' && argv[1][1] == '\0') ||
	(argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2] == '\0'))
		get_input();
	execute_cat(argc, argv);
	return (0);
}
