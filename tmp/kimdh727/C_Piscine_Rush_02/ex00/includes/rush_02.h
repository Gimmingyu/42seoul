/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 12:24:18 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/09 21:25:47 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# define BUF_SIZE 4096

/*
**	s_dict 구조체
**	size, key, value
*/

typedef	struct	s_dict
{
	int		size;
	char	**key;
	char	**value;
}				t_dict;

/*
**	g_flag statement
**	0x1			= print any
**	0x10		= t_dict malloc error
**	0x20		= key malloc error
**	0x40		= value malloc error
**	0x80		= data error
**	0x100 		= dcit error
**	0x1000		= input data error
**	0x2000		= read file error
*/

int				g_flag;

/*
**	rush_02.c function
*/

void			rush_02(int argc, char *argv[]);
void			rush_02_solve(char *dict, char *value);
void			get_solution(char *value, t_dict *dict);

/*
**	ft basic.c function
*/

void			ft_putstr(char *str);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(char *str, int st, int en);
char			*ft_trim(char *str);

/*
**	controller.c function
*/

int				is_num(char c);
int				is_printable(char c);
int				is_space(char c);
int				is_key(char *str);
int				is_value(char *str);

/*
**	ft split.c function
*/

char			**ft_split(char *str, char *charset);

/*
**	get_dict.c function
*/

char			*read_buf(char *dict, char *dest);
char			*get_dict_buf(char *dict);
int				trim_dict(char **split, int size);
int				key_val_init(char *str, int num, t_dict *dict);
t_dict			*dict_init(char **split, int dict_size);

/*
**	print.c function
*/

void			print_one(char *str, t_dict *dict);
void			print_ten(char *str, t_dict *dict, char split);
void			print_hundread(char *str, t_dict *dict);
void			print_num(char *value, int ref, t_dict *dict);
void			print_digit(int ref, t_dict *dict);

/*
**	memory_manage.c function
*/

void			free_key(t_dict *dict);
void			free_value(t_dict *dict);
void			free_dict(t_dict *dict);
void			free_dict_split(char **split, int size);

/*
**	checker.c	function
*/

void			ft_swap(char *a, char *b);
void			space_process(char *str);
int				key_check(t_dict *dict);
int				value_check(t_dict *dict);
int				dict_check(t_dict *dict);

/*
** 	solver.c	function
*/

t_dict			*get_dict(char *dict);
char			*make_digit(int digit);
void			get_solution(char *value, t_dict *dict);

#endif
