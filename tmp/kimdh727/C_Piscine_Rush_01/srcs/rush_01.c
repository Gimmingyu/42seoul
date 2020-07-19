/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 15:13:30 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/02 21:54:25 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush_01.h"

/*
** This FUNCTION get string pointer		input : argv string pointer
** get unsigned number
** it is not valid number		return -1
** it is white space			return 0
** it is number(in int range)	return number
** CAUTION : string pointer move end of number string + 1
*/

int		string_to_num(char **str)
{
	int state;
	int result;

	state = 0;
	result = 0;
	while (**str)
	{
		if (!state && **str >= '1' && **str <= '9')
		{
			state = 1;
			result = **str - '0';
		}
		else if (state && **str >= '0' && **str <= '9')
			result = result * 10 + (**str - '0');
		else if (**str == ' ' || (**str >= 9 && **str <= 13))
			break ;
		else
			return (-1);
		(*str)++;
	}
	return (result);
}

/*
** This FUNCTION get MAP size		input str : argv
** it is not valid size	return 0
** it is valid size 	return size
** i : iteration
** cnt : count size
** temp : temp store num
*/

int		get_size(char *str)
{
	int i;
	int cnt;
	int temp;

	i = 0 - 1;
	cnt = 0;
	while (*str)
	{
		temp = string_to_num(&str);
		if (temp > 0)
			cnt++;
		else if (temp == -1)
			return (0);
		str = (!*str) ? str : str + 1;
	}
	i = 1;
	while (i * 4 < cnt && i * i > 0)
		i++;
	if (i * 4 == cnt)
		return (i);
	return (0);
}

/*
** This FUNCTION get solution array use backtracking algorithm
** cnt : now counter
** i : iteration
** x : row index
** y : col index
** if cnt == g_num x g_num
** 		check result is true => print result
** else
** 		find next case
*/

void	backtracking(int cnt, int **checker)
{
	int i;
	int x;
	int y;

	if (cnt == (g_num * g_num))
	{
		check_result(checker);
		return ;
	}
	x = cnt % g_num;
	y = cnt / g_num;
	i = 0 - 1;
	while (++i < g_num)
		if (!g_row[x][i] && !g_col[y][i])
		{
			g_row[x][i] = 1;
			g_col[y][i] = 1;
			g_map[x][y] = i + 1;
			backtracking(cnt + 1, checker);
			if (g_flag)
				return ;
			g_row[x][i] = 0;
			g_col[y][i] = 0;
		}
}

/*
** This FUNCTION solve rush 01 problem
** get error condition and manage memory
**
** First Error is input size not valid
** if size is valid then global init and get checker array
** else print Error + terminate func
**
** Second Error is input num not valid
** if input num is valid start backtraking start
** else print Error + free memory allocation + terminate func
**
** Third Error is Can't find result
** if Can't find result print Error
**
** free all memoey and terminate func
*/

void	solve_rush_01(char *argv)
{
	int size;
	int **checker;

	if (!(size = get_size(argv)))
	{
		write(1, "Error\n", 6);
		return ;
	}
	global_init(size);
	checker = get_checker(argv);
	if (g_flag == -1)
	{
		write(1, "Error\n", 6);
		free_all(checker);
		return ;
	}
	backtracking(0, checker);
	if (!g_flag)
		write(1, "Error\n", 6);
	free_all(checker);
}

/*
** Call solver iteration = argc
*/

void	rush_01(int argc, char *argv[])
{
	int i;

	i = 0 - 1;
	while (++i < argc)
		solve_rush_01(argv[i]);
}
