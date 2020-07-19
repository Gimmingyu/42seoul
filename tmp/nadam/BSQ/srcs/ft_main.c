/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:11:13 by jko               #+#    #+#             */
/*   Updated: 2020/02/12 22:34:56 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "stdin_reader.h"
#include "map_reader.h"
#include "map_validation.h"
#include "largest_square_finder.h"
#include "answer_printer.h"

char	solve(t_map_info *map_info)
{
	t_answer	*answer;

	if (!is_valid_map(map_info))
	{
		write(1, "map error\n", 10);
		return (1);
	}
	if ((answer = find_largest_square(map_info)) == 0)
		return (-1);
	mark_largest_square(map_info, answer);
	print_answer(map_info);
	free(answer);
	return (0);
}

char	read_and_solve(char *file_name)
{
	t_map_info	*map_info;
	t_map_info	*(*func)(char *);

	if (file_name == 0)
		func = &read_map_info_from_stdin;
	else
		func = &read_map;
	if ((map_info = func(file_name)) == 0)
	{
		write(2, "map error\n", 10);
		return (-1);
	}
	if (solve(map_info) < 0)
	{
		free_map_info(map_info);
		return (-1);
	}
	free_map_info(map_info);
	return (0);
}

int		main(int argc, char **argv)
{
	int			i;

	if (argc < 2)
	{
		if (read_and_solve(0) != 0)
			return (-1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (read_and_solve(argv[i]) != 0)
			return (-1);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
