/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 08:24:42 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/12 16:40:34 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_dfs(int idx, int *udlr[], int *ans)
{
	int i;

	if (idx == N * N)
		return (1);
	else
	{
		i = 1;
		while (i <= N)
		{
			ans[idx] = i++;
			if (!ft_check(idx, udlr, ans))
				continue;
			if (ft_dfs(idx + 1, udlr, ans))
				return (1);
		}
	}
	return (0);
}
