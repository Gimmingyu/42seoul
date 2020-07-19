/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jushin <jushin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:02:30 by jko               #+#    #+#             */
/*   Updated: 2020/02/12 14:24:36 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "dict.h"
#include "hash.h"
#include "file_to_hash.h"
#include "input_validation.h"
#include "find.h"
#include "print_entry.h"

char	program(char *file_name, char *key)
{
	t_dict	**hash;
	int		result;

	if (!is_valid(key))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	hash = read_file_and_make_hash(file_name);
	if (hash == 0)
	{
		write(2, "Dict Error\n", 11);
		return (-1);
	}
	result = find_num(hash, key);
	if (result == -1)
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	free_hash(hash);
	return (0);
}

char	check_args(int argc)
{
	if (argc == 1)
	{
		print_entry(DICT_FILE);
		return (-1);
	}
	else if (argc > 3)
	{
		write(2, "Args Error\n", 11);
		return (-1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char *key;
	char *file_name;

	if (check_args(argc) != 0)
		return (-1);
	file_name = argc == 2 ? DICT_FILE : argv[1];
	key = argc == 2 ? argv[1] : argv[2];
	if (program(file_name, key) != 0)
		return (-1);
	return (0);
}
