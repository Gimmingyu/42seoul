/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yju <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:22:10 by yju               #+#    #+#             */
/*   Updated: 2020/07/12 23:33:57 by yju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

int		**ft_malloc(int square_root)
{
	int row;
	int col;
	int **arr_malloc;

	arr_malloc = (int *)ft_malloc(sizeof(int *), square_root);
	row = 0;
	while (row < square_root)
	{
		arr_malloc[row] = (int *)ft_malloc(sizeof(int *), square_root);
		row++;
	}
	row = 0;
	while (row < square_root)
	{
		col = 0;
		while (col < square_root){
			arr_malloc[row][col] = 0;
			col++;
		}
		row++;
	}
	return arr_malloc;
}
