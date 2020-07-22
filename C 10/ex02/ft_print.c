/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 13:03:44 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/21 15:30:27 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_print_newline(void)
{
	if (g_newline_flag)
		write(1, "\n", 1);
	else
		g_newline_flag = 1;
}

void	ft_print_content(int cnum, int argc, int file, char *str)
{
	char	c;
	int		i;
	int		j;
	int		tmp_file;

	i = 0;
	tmp_file = open(str, O_RDONLY);
	while (read(tmp_file, &c, sizeof(char)))
		i++;
	ft_print_newline();
	if (argc > 4)
	{
		ft_putstr("==> ");
		ft_putstr(str);
		ft_putstr(" <==\n");
	}
	j = 0;
	while (read(file, &c, 1))
	{
		if (i - cnum <= j)
			write(1, &c, sizeof(char));
		j++;
	}
}

void	ft_print_tail(int argc, char *argv[])
{
	int		i;
	int		cnum;
	int		file;

	i = 3;
	cnum = ft_get_num(argv[2]);
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
			ft_print_content(cnum, argc, file, argv[i]);
		i++;
	}
}
