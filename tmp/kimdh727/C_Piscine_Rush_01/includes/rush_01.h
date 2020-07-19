/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 18:57:23 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/02 18:57:27 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_01_H
# define RUSH_01_H

/*
** g_num : global num (size)
** g_map : global data map 2D
** g_row : global row visit 2D
** g_col : global col visit 2D
** g_flag : global flag
*/

int		g_num;
int		**g_map;
int		**g_row;
int		**g_col;
int		g_flag;

void	global_init(int size);
void	free_all(int **checker);
void	print_num(unsigned int nb);
int		string_to_num(char **str);
int		get_size(char *str);
int		**get_checker(char *str);
void	compare(int comp, int *max, int *cnt);
int		checking(int *checker, int cr, int fix);
void	check_result(int **checker);
void	backtracking(int cnt, int **checker);
void	solve_rush_01(char *argv);
void	rush_01(int argc, char *argv[]);

#endif
