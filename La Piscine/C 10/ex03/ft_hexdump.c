/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:07:00 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 00:34:08 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_parse_hexdump(int argc, char *argv[])
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
			ft_print_hexdump(file, 0, 0);
		ft_reset_global();
		i++;
	}
}

void	ft_print_hex_content(char buf, int k)
{
	unsigned char	tmp;

	tmp = (unsigned char)buf;
	if (0 <= buf && buf < 16)
		write(1, "0", 1);
	ft_print_address(tmp);
	if (k != 15)
		write(1, " ", 1);
}

void	ft_print_hexdump(int file, int c, int i)
{
	char	buf[17];
	char	*cmp_buf;

	ft_init_buf(buf);
	while (read(file, &buf, sizeof(char) * 16))
	{
		ft_is_duplicate(cmp_buf, buf);
		if (g_flag == 0)
		{
			cmp_buf = ft_strdup(buf);
			g_flag = 1;
		}
		i += 16;
		if (g_flag == 1)
		{
			ft_print_offset_cnt(c);
			ft_print_center_content(buf);
		}
		c = i;
		ft_init_buf(buf);
	}
	ft_print_offset_cnt((c - (16 - g_last_cnt)));
	write(1, "\n", 1);
}
