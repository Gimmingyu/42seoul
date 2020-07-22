/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 16:07:00 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/22 00:25:38 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		main(int argc, char *argv[])
{
	if (argc >= 2)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'C' && argv[1][2] == '\0')
		{
			if (argc >= 3)
			{
				g_len = 0;
				ft_parse_c_hexdump(argc, argv);
			}
		}
		else
		{
			g_len = 7;
			ft_parse_hexdump(argc, argv);
		}
	}
	return (0);
}
