/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yju <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:27:03 by yju               #+#    #+#             */
/*   Updated: 2020/07/12 23:34:58 by yju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"

int		**ft_setting(int **arr_malloc, int *arr, int square_root)
{
	int i;

	i = 1;
	while (i < square_root - 1)
	{
		(*arr_malloc)[i] = *arr;
		arr++;
		i++;
	}
	i = 1;
	while (i < square_root - 1)
	{
		(arr_malloc[square_root - 1])[i] = *arr;
		arr++;
		i++;
	}
	i = 1;
	while (i < square_root - 1)
	{
		*arr_malloc[i] = *arr;
		arr++;
		i++;
	}
	i = 1;
	while (i < square_root - 1)
	{
		arr_malloc[i][square_root - 1] = *arr;
		arr++;
		i++;
	}
	return arr_malloc;
}
