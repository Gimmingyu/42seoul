/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 08:16:51 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/12 14:30:50 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

void	ft_print(int *ans)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < N * N)
	{
		ft_putchar(ans[i] + '0');
		if (i % N == N - 1)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i++;
	}
}
