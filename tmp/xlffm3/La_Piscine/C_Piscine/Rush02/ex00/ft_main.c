/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 09:25:16 by jipark            #+#    #+#             */
/*   Updated: 2020/02/09 22:38:16 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_h.h"

/*
**	[struct g_map] contains total size of dictionary, arrays of key strings,
**	and arrays of value strings.
**	[g_file] is assigned for containing return values of 'open' function.
**	[g_is_blank] is used as boolean determining if a current character
**	can be blank when check the format-validation of keys from dictionary.
**	[g_flag] is used wehn determining value and digits.
*/
t_map	g_map;
int		g_file = 0;
int		g_is_blank = 0;
int		g_flag = 0;

/*
**	[set_g_map] function is aimed to dynamically allocate member variables
**	of g_map. Also the function initalize elements of key string array
**	and value string array according to the dictionaray called dict_name.
**	If something unexpected happens, the function will return 0.
*/

int		set_g_map(char *dict_name)
{
	g_map.size = get_map_size(dict_name);
	if (!(g_map.key = (char **)malloc(sizeof(char *) * g_map.size)))
		return (0);
	if (!(g_map.value = (char **)malloc(sizeof(char *) * g_map.size)))
		return (0);
	if (!get_key_array(dict_name))
		return (0);
	if (!get_value_array(dict_name))
		return (0);
	if (!set_key_array(dict_name))
		return (0);
	if (!set_value_array(dict_name))
		return (0);
	trim_value_array();
	if (!check_valid_value())
		return (0);
	return (1);
}

/*
**	[get_free] function is aimed to free all dynamically allocated memories.
**	It will check whetehr it is allocated or not before executing free.
*/

void	get_free(char *key_num)
{
	int i;

	i = 0;
	while (i < g_map.size)
	{
		if (g_map.key[i] != 0)
			free(g_map.key[i]);
		if (g_map.value[i] != 0)
			free(g_map.value[i]);
		i++;
	}
	if (g_map.key != 0)
		free(g_map.key);
	if (g_map.value != 0)
		free(g_map.value);
	if (key_num != 0)
		free(key_num);
}

/*
**	[find_another_dictionary] function is where the program runs
**	if the number of arguments are three.
**	The logic is same as [main] function.
*/

void	find_new_dictionary(char *argv[], char *key_num)
{
	char *dict_name;

	dict_name = argv[1];
	if (!check_valid_number(argv[2]))
	{
		write(1, "Error\n", 6);
		return ;
	}
	if (!(key_num = get_trimed_number(argv[2])))
		return ;
	if (!set_g_map(dict_name))
		write(1, "Dict Error\n", 11);
	else
		get_result(key_num);
	return ;
}

/*
**	[main] function is where the main program runs.
**	There are two cases : the number of arguments are two or three.
*/

int		main(int argc, char *argv[])
{
	char *dict_name;
	char *key_num;

	key_num = 0;
	dict_name = "numbers.dict";
	if (argc == 2)
	{
		if (!check_valid_number(argv[1]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (!(key_num = get_trimed_number(argv[1])))
			return (0);
		if (!set_g_map(dict_name) || ft_strlen(key_num) >= 40)
			write(1, "Dict Error\n", 11);
		else
			get_result(key_num);
	}
	else if (argc == 3)
		find_new_dictionary(argv, key_num);
	get_free(key_num);
	return (0);
}
