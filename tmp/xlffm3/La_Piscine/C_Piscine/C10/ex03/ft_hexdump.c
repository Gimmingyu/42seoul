/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:11:44 by jipark            #+#    #+#             */
/*   Updated: 2020/02/13 16:35:03 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int	g_len = 0;
int	g_flag = 0;
int g_star_flag = 0;
int g_last_cnt = 0;
int g_offset_cnt = 0;

void	print_offset_cnt(int i)
{
	int k;
	int len;

	k = 0;
	len = check_length(i);
	while (k++ < g_len - len)
		write(1, "0", 1);
	if (i)
		print_address(i);
}

void	print_center_content(char *buf)
{
	int k;
	int cnt;

	k = 0;
	cnt = 0;
	write(1, " ", 1);
	while (k < 16 && buf[k] != '\0')
	{
		print_hex_content(buf[k], k);
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
	write(1, "\n", 1);
	g_last_cnt = k;
}

void	is_duplicate(char *cmp_buf, char buf[17])
{
	if (g_flag || g_flag == -1)
	{
		if (!ft_strcmp(cmp_buf, buf))
		{
			if (!g_star_flag)
			{
				write(1, "*\n", 2);
				g_star_flag = 1;
			}
			g_flag = -1;
		}
		else
		{
			g_flag = 0;
			g_star_flag = 0;
		}
	}
}

void	print_hexdump(int file, int c, int i)
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
			print_offset_cnt(c);
			print_center_content(buf);
		}
		c = i;
		init_buf(buf);
	}
	print_offset_cnt((c - (16 - g_last_cnt)));
	write(1, "\n", 1);
}

int		main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'C' && argv[1][2] == '\0')
		{
			if (argc >= 3)
			{
				g_len = 8;
				parse_c_hexdump(argc, argv);
			}
		}
		else
		{
			g_len = 7;
			parse_hexdump(argc, argv);
		}
	}
	return (0);
}
