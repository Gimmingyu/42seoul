/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 11:36:53 by marvin            #+#    #+#             */
/*   Updated: 2020/07/10 11:36:53 by marvin           ###   ########.fr       */
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
			letter = argv[1][i] + 1;
			if (argv[1][i] == 'z' || argv[1][i] == 'Z')
				letter -= 26;
			write(1, &letter, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}