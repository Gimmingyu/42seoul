/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:44:57 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 11:44:57 by marvin           ###   ########.fr       */
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
			letter = 0;
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				letter = argv[1][i] - 63;
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				letter = argv[1] - 95;
				while (--letter)
					write(1, &argv[1][i], 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}