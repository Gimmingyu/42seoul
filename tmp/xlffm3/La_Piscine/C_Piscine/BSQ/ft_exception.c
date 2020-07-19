/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 15:57:05 by jipark            #+#    #+#             */
/*   Updated: 2020/02/12 21:43:20 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

int		check_duplicate_char(void)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = i + 1;
		while (j < 3)
		{
			if (g_char_arr[i] == g_char_arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		check_new_line_exception(int j, int *index)
{
	if (j != g_col || g_col == 0)
		return (0);
	*index += 1;
	return (1);
}

void	handle_error(void)
{
	ft_putstr("map error\n");
	get_free();
	g_row = 0;
	g_col = 0;
	g_max = 0;
	g_error_flag = 0;
}

int		allocate_g_buf(void)
{
	if (!(g_buf = (char *)malloc(sizeof(char) * 20000)))
		return (0);
	g_buf_flag = 1;
	return (1);
}
