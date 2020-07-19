/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:53:46 by jipark            #+#    #+#             */
/*   Updated: 2020/02/06 21:27:02 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(2, str++, 1);
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

int		main(int argc, char const *argv[])
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
