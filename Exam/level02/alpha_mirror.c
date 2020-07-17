/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:30:52 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 12:30:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char *argv[])
{
	int		i;
	int		letter;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			letter = argv[1][i];
			if (argv[1][i] <= 'A' && argv[1][i] >= 'Z')
				letter = 'Z' - argv[1][i] + 'A';
			if (argv[1][i] <= 'a' && argv[1][i] >= 'z')
				letter = 'z' - argv[1][i] + 'a';
			write(1, &letter, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}