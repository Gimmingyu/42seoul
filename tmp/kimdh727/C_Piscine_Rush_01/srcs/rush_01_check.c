/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:36:46 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/02 19:20:43 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "rush_01.h"

/*
** This FUNCTION print number
*/

void	print_num(unsigned int nb)
{
	char print;

	if (nb >= 10)
		print_num(nb / 10);
	print = nb % 10 + '0';
	write(1, &print, 1);
}

/*
** This FUNCTION get checker 2D array	input str : argv
** Use g_nem and make checker
** PUSH	co11up		co11down
** 		col2up		col2down
** 		...			...
** 		rowN-1left	rowN-1right
** 		rowNleft	rowNright
** i : iteration
** checker : checking rule 2D array data
** temp : temp store num
** if input num > g_num : get fatal error
** if is valid num in col condition
** 			checker[i % g_num][i / g_num]
** if is valid num in row condition
** 			checker[i % g_num + g_num][i / g_num]
*/

int		**get_checker(char *str)
{
	int i;
	int **checker;
	int temp;

	checker = (int **)malloc(sizeof(int *) * (g_num) * 2);
	i = 0 - 1;
	while (++i < g_num * 2)
		checker[i] = (int *)malloc(sizeof(int) * 2);
	i = 0;
	while (*str)
	{
		temp = string_to_num(&str);
		if (temp > g_num)
			g_flag = -1;
		if (temp > 0)
		{
			if (i < g_num * 2)
				checker[i % g_num][i / g_num] = temp;
			else
				checker[i % g_num + g_num][i / g_num - 2] = temp;
			i++;
		}
		str = (!*str) ? str : str + 1;
	}
	return (checker);
}

/*
**	compare with comp arugument and *max value
**	if comp > *max
**	*max = comp and cnt++
*/

void	compare(int comp, int *max, int *cnt)
{
	if (comp > *max)
	{
		*max = comp;
		*cnt = *cnt + 1;
	}
}

/*
** This FUNCTION checking continue ...
** cr : get checking col or row conditon
** 		col = 0 / row = 1
** fix : get fix index
** 		in col condition fix row index
** 		in row condition fix col index
** it`s mean
** 		in col condition
** 			check map[fix][iter]
** 		in row condition
** 			check map[iter][fix]
** so we can get
** 		map[(iter * !cr) + (fix * cr)][(iter * cr) + (fix * !cr)]
** i : iteration
** max : max val
** cnt : count val
*/

int		checking(int *checker, int cr, int fix)
{
	int i;
	int max;
	int cnt;

	i = 0 - 1;
	max = 0;
	cnt = 0;
	while (++i < g_num)
		compare(g_map[i * !cr + fix * cr][i * cr + fix * !cr], &max, &cnt);
	if ((cnt != checker[0]))
		return (0);
	max = 0;
	cnt = 0;
	while (i-- > 0)
		compare(g_map[i * !cr + fix * cr][i * cr + fix * !cr], &max, &cnt);
	if ((cnt != checker[1]))
		return (0);
	return (1);
}

/*
** This FUNCTION checking solution
** i : iteration for row
** j : iteration for col
** checker array size is [g_num x 2][2]
** give to checking function
** 		checker => checker
** 		cr(col or row) => c : 0 / r : 1 is same i / g_num
** 		fix index => i % g_num
** check all case true
** 		print data
**		global flag set (= find 1 case and terminate searching)
*/

void	check_result(int **checker)
{
	int	i;
	int	j;

	i = 0 - 1;
	while (++i < g_num * 2)
		if (!(checking(checker[i], i / g_num, i % g_num)))
			return ;
	i = 0 - 1;
	while (++i < g_num)
	{
		j = 0 - 1;
		while (++j < g_num)
		{
			print_num(g_map[i][j]);
			write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
	g_flag = 1;
}
