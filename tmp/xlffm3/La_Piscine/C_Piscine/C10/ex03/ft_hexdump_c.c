/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:00:50 by jipark            #+#    #+#             */
/*   Updated: 2020/02/13 16:36:11 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	print_offset_c_cnt(int i)
{
	int k;
	int len;

	k = 0;
	len = check_length(i);
	while (k++ < g_len - len)
		write(1, "0", 1);
	if (i)
		print_address(i);
	write(1, " ", 1);
}

void	parse_c_hexdump(int argc, char *argv[])
{
	int i;
	int file;

	i = 2;
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
			print_c_hexdump(file, 0, 0);
		reset_global();
		i++;
	}
}

void	print_c_hex_content(char buf, int k)
{
	unsigned char	tmp;

	tmp = (unsigned char)buf;
	if (0 <= buf && buf < 16)
		write(1, "0", 1);
	print_address(tmp);
	if (k != 15)
		write(1, " ", 1);
	if (k == 7)
		write(1, " ", 1);
}

void	print_center_c_content(char *buf)
{
	int k;
	int cnt;

	k = 0;
	cnt = 0;
	write(1, " ", 1);
	while (k < 16 && buf[k] != '\0')
	{
		print_c_hex_content(buf[k], k);
		k++;
	}
	if (k != 16)
	{
		while (cnt < 3 * (16 - k) - 1)
		{
			write(1, " ", 1);
			cnt++;
		}
	}
	if (k < 7)
		write(1, " ", 1);
	g_last_cnt = k;
}

void	print_c_hexdump(int file, int c, int i)
{
	char	buf[17];
	char	*cmp_buf;

	init_buf(buf);
	while (read(file, &buf, sizeof(char) * 16))
	{
		is_duplicate(cmp_buf, buf);
		if (g_flag == 0)
		{
			cmp_buf = ft_strdup(buf);
			g_flag = 1;
		}
		i += 16;
		if (g_flag == 1)
		{
			print_offset_c_cnt(c);
			print_center_c_content(buf);
			print_raw_content(buf);
		}
		c = i;
		init_buf(buf);
	}
	print_offset_cnt((c - (16 - g_last_cnt)));
	write(1, "\n", 1);
}
