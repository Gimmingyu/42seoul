/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:13:22 by jko               #+#    #+#             */
/*   Updated: 2020/02/04 18:03:20 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	init_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

int		**malloc_arrs(int n)
{
	int		i;
	int		**result;

	result = (int **)malloc(sizeof(int *) * n);
	i = 0;
	while (i < n)
		result[i++] = (int *)malloc(sizeof(int) * n);
	return (result);
}

void	free_arrs(int **arrs, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(arrs[i]);
		i++;
	}
	free(arrs);
}
