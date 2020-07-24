/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_udlr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 21:52:39 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/12 16:33:02 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** (main) ft_check_udlr
** (sub1) u_check: Up check, idx: 12, 13, 14, 15
** (sub2) d_check: Down check, idx: 12, 13, 14, 15
** (sub3) l_check: Left check, idx: 3, 7, 11, 15
** (sub4) r_check: Right check, idx: 3, 7, 11, 15
*/

#include "header.h"

int		u_check(int idx, int *udlr[], int *ans)
{
	int i;
	int u_val;
	int tmp;

	i = 0;
	u_val = 1;
	while (idx % N == N - 1)
	{
		tmp = ans[idx - (N * N - N) + (N * i)];
		while (i < N - 1)
		{
			if (tmp < ans[idx - N * N + (N * i)])
			{
				tmp = ans[idx - N * N + (N * i)];
				u_val++;
			}
			i++;
		}
		if (u_val == udlr[0][idx % (N * N - N)])
			return (1);
		else
			return (0);
	}
	return (1);
}

int		d_check(int idx, int *udlr[], int *ans)
{
	int i;
	int d_val;
	int tmp;

	i = 0;
	d_val = 1;
	while (idx % N == N - 1)
	{
		tmp = ans[idx];
		while (i < N - 1)
		{
			if (tmp < ans[idx - N - (N * i)])
			{
				tmp = ans[idx - N - (N * i)];
				d_val++;
			}
			i++;
		}
		if (d_val == udlr[1][idx % (N * N - N)])
			return (1);
		else
			return (0);
	}
	return (1);
}

int		l_check(int idx, int *udlr[], int *ans)
{
	int i;
	int j;
	int l_val;
	int tmp;

	i = 1;
	j = 1;
	l_val = 1;
	while (j <= N)
	{
		if (idx == j * N - 1)
		{
			tmp = ans[idx - (N - 1)];
			while (i < N)
			{
				if (tmp < ans[idx - (N - 1) + i])
				{
					tmp = ans[idx - (N - 1) + i];
					l_val++;
				}
				i++;
			}
			if (l_val == udlr[2][idx / N])
				return (1);
			else
				return (0);
		}
		j++;
	}
	return (1);
}

int		r_check(int idx, int *udlr[], int *ans)
{
	int i;
	int j;
	int r_val;
	int tmp;

	i = 1;
	j = 1;
	r_val = 1;
	while (j <= N)
	{
		if (idx == j * N - 1)
		{
			tmp = ans[idx];
			while (i < N)
			{
				if (tmp < ans[idx - i])
				{
					tmp = ans[idx - i];
					r_val++;
				}
				i++;
			}
			if (r_val == udlr[3][idx / N])
				return (1);
			else
				return (0);
		}
		j++;
	}
	return (1);
}

int		ft_check_udlr(int idx, int *udlr[], int *ans)
{
	if (u_check(idx, udlr, ans) && d_check(idx, udlr, ans)
			&& l_check(idx, udlr, ans) && r_check(idx, udlr, ans))
		return (1);
	return (0);
}
