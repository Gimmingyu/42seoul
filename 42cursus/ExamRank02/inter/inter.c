/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 03:10:47 by kyekim            #+#    #+#             */
/*   Updated: 2021/03/30 03:12:16 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check(char* str, char c, int idx)
{
	int		i;
	
	i = 0;
	while (i < idx)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char* argv[])
{
	int		i;
	int		j;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i])
		{
			if (check(argv[1], argv[1][i], i) == 0)
			{
				j = 0;
				while (argv[2][j])
				{
					if (argv[2][j] == argv[1][i])
					{
						ft_putchar(argv[1][i]);
						break;
					}
					j++;
				}
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}