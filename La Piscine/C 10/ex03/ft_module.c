/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_module.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:44:45 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/21 16:51:57 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

void	ft_reset_global(void)
{
	g_flag = 0;
	g_star_flag = 0;
	g_last_cnt = 0;
}

void	ft_init_buf(char *buf)
{
	int		i;

	i = 0;
	while (i < 17)
		buf[i++] = 0;
}

int		ft_check_length(unsigned long long addr)
{
	int		cnt;

	cnt = 0;
	while (addr != 0)
	{
		addr /= 16;
		cnt++;
	}
	return (cnt);
}

void	ft_is_duplicate(char *cmp_buf, char buf[17])
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
