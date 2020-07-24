/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:47:16 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/21 15:54:45 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_get_input(void)
{
	char	c;

	while (read(0, &c, 1))
		write(1, &c, 1);
}

void	ft_print_file(int file)
{
	char c;

	while (read(file, &c, 1))
		write(1, &c, 1);
}

void	execute_cat(int argc, char *argv[])
{
	int		file;
	int		i;

	i = 1;
	while (i < argc)
	{
		file = open(argv[1], O_RDONLY);
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
			ft_print_file(file);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc <= 1 || (argv[1][0] == '-' && argv[1][1] == '\0')
	|| (argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2] == '\0'))
		ft_get_input();
	execute_cat(argc, argv);
	return (0);
}
