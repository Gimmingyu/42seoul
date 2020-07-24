/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 06:15:59 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/12 16:19:59 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char *argv[])
{
	int result;
	int **udlr;
	int *ans;
	int i;

	if (!ft_exceptions(argc, argv))
		write(1, "Error\n", 6);
	else
	{
		ans = (int *)malloc(sizeof(int) * N * N);
		udlr = (int **)malloc(sizeof(int *) * N);
		i = 0;
		while (i < N)
			udlr[i++] = (int *)malloc(sizeof(int) * N);
		ft_atoi(argv[1], udlr);
		result = ft_dfs(0, udlr, ans);
		if (result)
			ft_print(ans);
		else
			write(1, "No Answer\n", 10);
		ft_free(ans, udlr);
	}
	return (0);
}
