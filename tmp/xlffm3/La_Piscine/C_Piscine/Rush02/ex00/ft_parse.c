/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:54:24 by jipark            #+#    #+#             */
/*   Updated: 2020/02/09 23:00:30 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

/*
**	[get_result] function is aimed to call all the functions necessary for
**	displaying results.
*/

void	get_result(char *value)
{
	int		start;
	int		end;
	int		ref;
	char	*target;

	start = 0;
	end = ft_strlen(value);
	ref = (end - 1) / 3;
	end = start + (end - 1) % 3 + 1;
	while (ref >= 0)
	{
		target = ft_strdup(value, start, end);
		print_num(target, end - start);
		if (ref && ft_strcmp(target, (char *)"000"))
			print_digit(ref);
		start = end;
		end = end + 3;
		ref--;
	}
	if (!g_is_blank)
		write(1, "Dict Error\n", 11);
	else
		write(1, "\n", 1);
}

/*
**	[make_digit] function is aimed to make decimal number starting with '1'.
**	The number of digis are following size parameter.
*/

char	*make_digit(int size)
{
	char	*arr;
	int		i;

	arr = (char *)malloc(sizeof(char) * size + 1);
	arr[0] = '1';
	i = 1;
	while (i < size)
		arr[i++] = '0';
	arr[i] = '\0';
	return (arr);
}
