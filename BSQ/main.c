/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 10:58:16 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/23 08:15:04 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char *argv[])
{
	int		i;
	t_map	info;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			info = file_to_struct(argv[i]);
			find_square(&info);
			print_map(&info);
			i++;
		}
	}
	return (0);
}
