/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wochoi <wochoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 14:37:37 by wochoi            #+#    #+#             */
/*   Updated: 2020/07/15 20:06:09 by wochoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void		print_argv_name(int i, char *str)
{
	if (i != 3)
	{
		print("\n");
	}
	print("==> ");
	print(str);
	print(" <==\n");
}

int			print_argv_tail(char *file, int n)
{
	char	*temp;
	int		len;
	int		i;
	int		fd;

	temp = (char *)malloc(sizeof(char) * 2 * n);
	if (!temp || (fd = open(file, O_RDONLY)) == -1)
		return (1);
	len = read(fd, temp, n);
	while ((len = read(fd, temp + n, n)) > 0)
	{
		i = 0;
		while (i < n)
		{
			temp[i] = temp[i + len];
			++i;
		}
	}
	close(fd);
	temp[n] = '\0';
	print(temp);
	if (len < 0)
		return (1);
	return (0);
}

int			print_stdin_tail(int n)
{
	char	*temp;
	int		len;
	int		i;

	temp = (char *)malloc(sizeof(char) * 2 * n);
	if (!temp)
		return (1);
	len = read(STDIN_FILENO, temp, n);
	while ((len = read(STDIN_FILENO, temp + n, n)) > 0)
	{
		i = 0;
		while (i < n)
		{
			temp[i] = temp[i + len];
			++i;
		}
	}
	temp[n] = '\0';
	print(temp);
	if (len < 0)
		return (1);
	return (0);
}

int			tail_c(int argc, char **argv, int n)
{
	int		i;

	if (argc == 3)
	{
		if (print_stdin_tail(n))
			return (1);
	}
	if (argc == 4)
	{
		if (print_argv_tail(argv[3], n))
			return (1);
	}
	else
	{
		i = 3;
		while (i < argc)
		{
			print_argv_name(i, argv[i]);
			if (print_argv_tail(argv[i], n))
				return (1);
			++i;
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		n;

	if ((n = check_valid_input(argc, argv)) < 0)
		return (1);
	if (tail_c(argc, argv, n))
		return (1);
	return (0);
}
