/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
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

int		main(int argc, char* argv[])
{
	int		i;
	int		j;
	int		flag[255] = {0};

	if (argc == 3)
	{
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!flag[(unsigned char)argv[i][j]])
				{
					flag[(unsigned char)argv[i][j]] = 1;
					ft_putchar(argv[i][j]);
				}
				j++;
			}
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}