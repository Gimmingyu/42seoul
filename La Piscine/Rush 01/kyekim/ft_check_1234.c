/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_1234.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 08:05:49 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/12 17:47:54 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_check_1234: check overlap number
** only exist unique value: 1, 2, 3, 4
*/

#include "header.h"

int		ft_check_1234(int idx, int *ans)
{
	int i;
	int j;
	int k;

	i = idx % N;
	j = idx / N;
	k = 1;
	while (i-- != 0)
	{
		if (ans[idx] == ans[idx - k++])
			return (0);
	}
	k = N;
	while (j >= 0)
	{
		if (ans[idx] == ans[idx - 1])
			return (0);
		k += N;
		j -= 1;
	}
	return (1);
}
