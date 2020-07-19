/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jushin <jushin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:49:01 by jushin            #+#    #+#             */
/*   Updated: 2020/02/12 14:24:42 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "dict.h"
#include "ft_string.h"
#include "ft_string2.h"
#include "hash.h"

int		find_in_dict(t_dict **hash, char *to_find)
{
	int		hash_idx;
	t_dict	*tmp;

	hash_idx = 0;
	while (hash_idx < BIG_PRIME_NUM)
	{
		if (hash[hash_idx] == '\0')
		{
			hash_idx++;
			continue;
		}
		tmp = hash[hash_idx];
		while (tmp != 0)
		{
			if (ft_strcmp(tmp->key, to_find) == 0)
			{
				write(1, tmp->value, ft_strlen(tmp->value));
				return (0);
			}
			tmp = tmp->next;
		}
		hash_idx++;
	}
	return (-1);
}

int		split_by_digit(char *to_find)
{
	int		idx;
	int		len;

	idx = 0;
	len = 0;
	while (to_find[idx] != '\0')
	{
		if (idx % 3 == 0)
			len++;
		idx++;
	}
	return (len);
}

void	put_by_digit(char **arr, char *str, int size)
{
	int		row;
	int		len;
	int		unit;
	int		str_idx;

	row = 0;
	len = ft_strlen(str);
	str_idx = 0;
	while (row < size)
	{
		if (len % 3 == 0)
			unit = 3;
		else
			unit = len % 3;
		arr[row] = (char *)malloc(sizeof(char) * (unit + 1));
		arr[row] = ft_strncpy(arr[row], &str[str_idx], unit);
		len -= unit;
		str_idx += unit;
		row++;
	}
}

void	print_digit(t_dict **hash, int digit)
{
	char	arr[digit + 2];
	int		idx;

	if (digit > 0)
	{
		arr[0] = '1';
		idx = 1;
		while (idx <= digit)
		{
			arr[idx] = '0';
			idx++;
		}
		arr[idx] = '\0';
		write(1, " ", 1);
		find_in_dict(hash, arr);
	}
}

int		num_max_len(t_dict **hash)
{
	int		hash_idx;
	int		max_len;
	t_dict	*tmp;

	hash_idx = 0;
	max_len = 0;
	while (hash_idx < BIG_PRIME_NUM)
	{
		if (hash[hash_idx] == '\0')
		{
			hash_idx++;
			continue;
		}
		tmp = hash[hash_idx];
		while (tmp != 0)
		{
			if (ft_strlen(tmp->key) > max_len)
				max_len = ft_strlen(tmp->key);
			tmp = tmp->next;
		}
		hash_idx++;
	}
	return (max_len);
}
