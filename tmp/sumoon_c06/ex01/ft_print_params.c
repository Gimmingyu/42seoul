/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumoon <sumoon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 15:04:58 by sumoon            #+#    #+#             */
/*   Updated: 2020/07/15 19:26:11 by sumoon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int index;

	index = 1;
	while (index < argc)
	{
		while (*argv[index])
			write(1, argv[index]++, 1);
		write(1, "\n", 1);
		index++;
	}
	return (0);
}
