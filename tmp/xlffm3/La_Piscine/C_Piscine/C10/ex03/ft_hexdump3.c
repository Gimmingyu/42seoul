/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:51:39 by jipark            #+#    #+#             */
/*   Updated: 2020/02/13 16:35:56 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	parse_hexdump(int argc, char *argv[])
{
	int i;
	int file;

	i = 1;
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
			print_hexdump(file, 0, 0);
		reset_global();
		i++;
	}
}

void	reset_global(void)
{
	g_flag = 0;
	g_star_flag = 0;
	g_last_cnt = 0;
}

void	print_raw_content(char *buf)
{
	int i;

	i = 0;
	write(1, "  |", 3);
	while (i < 16)
	{
		if (buf[i] <= 31 || buf[i] >= 127)
			write(1, ".", 1);
		else
			write(1, &buf[i], 1);
		i++;
	}
	write(1, "|", 1);
	write(1, "\n", 1);
}
