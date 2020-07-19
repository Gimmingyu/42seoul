/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:56:48 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 21:23:22 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "dict.h"
#include "dict_list.h"
#include "hash.h"

int		get_hash_index(char *str)
{
	int result;
	int i;

	if (!str[0])
		return (-1);
	result = str[0];
	i = 1;
	while (str[i])
	{
		result = (result * 10 % BIG_PRIME_NUM)
			+ ((str[i] - '0') % BIG_PRIME_NUM);
		result %= BIG_PRIME_NUM;
		i++;
	}
	return (result);
}

t_dict	**init_hash(void)
{
	t_dict	**hash;
	int		i;

	hash = (t_dict **)malloc(sizeof(t_dict *) * BIG_PRIME_NUM);
	if (hash == 0)
		return (0);
	i = 0;
	while (i < BIG_PRIME_NUM)
	{
		hash[i] = 0;
		i++;
	}
	return (hash);
}

t_dict	*put_dict(t_dict **hash, t_dict *new_dict)
{
	int		hash_index;
	t_dict	*curr;

	hash_index = get_hash_index(new_dict->key);
	if (hash_index == -1)
		return (0);
	if (hash[hash_index] == 0)
	{
		hash[hash_index] = new_dict;
		return (new_dict);
	}
	if ((curr = find_dict_in_list(hash[hash_index], new_dict->key)))
		return (change_dict_value(curr, new_dict));
	return (add_dict_list(hash[hash_index], new_dict));
}

t_dict	*get_dict(t_dict **hash, char *key)
{
	int		hash_index;
	t_dict	*curr;

	hash_index = get_hash_index(key);
	if (hash_index == -1)
		return (0);
	curr = hash[hash_index];
	return (find_dict_in_list(curr, key));
}

void	free_hash(t_dict **hash)
{
	int i;

	i = 0;
	while (i < BIG_PRIME_NUM)
	{
		free_dict_list(hash[i]);
		i++;
	}
	free(hash);
}
