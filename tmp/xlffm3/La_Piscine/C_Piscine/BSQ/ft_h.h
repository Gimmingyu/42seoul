/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:32:14 by jipark            #+#    #+#             */
/*   Updated: 2020/02/12 22:01:04 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_H_H
#	define FT_H_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

extern int		g_col;
extern int		g_row;
extern int		g_max;
extern int		**g_map;
extern char		*g_char_arr;
extern int		g_new_line_flag;
extern int		g_error_flag;
extern char		*g_buf;
extern int		g_buf_flag;

int		allocate_g_map(void);
int		init_g_map(int file, int i);
int		extract_char(char *name, int cnt);
int		parse_file(char *name);

int		get_value(int y, int x);
void	draw_answer_square(int first_max_index[2]);
void	find_first_big_square(int first_max_index[2]);
void	convert_int_to_char(void);

void	print_map(void);
void	get_solution(void);
void	get_free(void);

int		check_duplicate_char(void);
int		check_row_exception(char *name);
int		check_new_line_exception(int j, int *index);
void	handle_error(void);

int		extract_std_char(char *buf, int cnt);
int		init_std_first_line(char *buf);
int		init_std_g_map(int i, int j, int index);
int		get_std_first_line(char *buf);
int		get_std_input(char c, int i);
int		allocate_g_buf(void);

void	ft_putstr(char *str);
#	endif
