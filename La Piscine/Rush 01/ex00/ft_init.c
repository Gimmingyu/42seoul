/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yju <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:33:25 by yju               #+#    #+#             */
/*   Updated: 2020/07/12 23:33:16 by yju              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"

int		**ft_init(int *arr)
{
	int square_root;
	int **arr_malloc;
	int **arr_init;

	square_root = ft_sqrt(arr);
	arr_malloc = ft_malloc_init(square_root + 2);
	arr_init = ft_setting(arr_malloc, arr, square_root + 2);
	return arr_init;
}
