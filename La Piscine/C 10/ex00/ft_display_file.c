/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:31:39 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/21 15:54:09 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	print_file(int file)
{
	char	c;
	int		flag;

	flag = 0;
	while (1)
	{
		flag = read(file, &c, sizeof(char));
		if (!flag)
			break ;
		write(1, &c, 1);
	}
}

int		main(int argc, char *argv[])
{
	int		file;

	if (argc <= 1)
	{
		ft_putstr("File name missing.");
		return (1);
	}
	else if (argc >= 3)
	{
		ft_putstr("Too many arguments.");
		return (1);
	}
	else
	{
		file = open(argv[1], O_RDONLY);
		if (file == -1)
		{
			ft_putstr("Cannot read file.");
			return (1);
		}
		else
			print_file(file);
		close(file);
	}
	return (0);
}
