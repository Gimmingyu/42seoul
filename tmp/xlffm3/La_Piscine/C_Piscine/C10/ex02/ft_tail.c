/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 15:18:00 by jipark            #+#    #+#             */
/*   Updated: 2020/02/13 14:29:24 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		g_newline_flag = 0;

void	print_newline(void)
{
	if (g_newline_flag)
		write(1, "\n", 1);
	if (!g_newline_flag)
		g_newline_flag = 1;
}

void	print_content(int c_num, int argc, int file, char *str)
{
	char	c;
	int		i;
	int		j;
	int		tmp_file;

	i = 0;
	tmp_file = open(str, O_RDONLY);
	while (read(tmp_file, &c, sizeof(char)))
		i++;
	print_newline();
	if (argc > 4)
	{
		ft_putstr("==> ");
		ft_putstr(str);
		ft_putstr(" <==\n");
	}
	j = 0;
	while (read(file, &c, sizeof(char)))
	{
		if (i - c_num <= j)
			write(1, &c, 1);
		j++;
	}
}

void	print_tail(int argc, char *argv[])
{
	int i;
	int c_num;
	int file;

	i = 3;
	c_num = get_number(argv[2]);
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (file == -1)
		{
			if (errno == 2)
			{
				ft_putstr(basename(argv[0]));
				ft_putstr(": ");
				ft_putstr(argv[i]);
				ft_putstr(": ");
			}
			ft_putstr(strerror(errno));
			ft_putstr("\n");
		}
		else
			print_content(c_num, argc, file, argv[i]);
		i++;
	}
}

void	get_input(int argc, char *argv[], int i, int j)
{
	char	tmp[20000];

	if (argc == 3)
	{
		while (read(0, &tmp[i], sizeof(char)))
			i++;
		tmp[i] = '\0';
		j = i - get_number(argv[2]);
		while (tmp[j] != '\0')
		{
			write(1, &tmp[j], 1);
			j++;
		}
	}
	else if (argc == 1)
	{
		while (read(0, &tmp[i], sizeof(char)))
			i++;
		tmp[i] = '\0';
		ft_putstr(tmp);
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 1 || (argc == 3 && check_only_number(argv[2])))
		get_input(argc, argv, 0, 0);
	if (argc < 3)
		return (0);
	if (!check_only_number(argv[2]))
	{
		ft_putstr(basename(argv[0]));
		ft_putstr(": illegal offset -- ");
		ft_putstr(argv[2]);
		write(1, "\n", 1);
		return (0);
	}
	else
	{
		if (argc >= 4)
			print_tail(argc, argv);
	}
	return (0);
}
