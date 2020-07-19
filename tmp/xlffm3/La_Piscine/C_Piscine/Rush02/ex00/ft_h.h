/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:32:14 by jipark            #+#    #+#             */
/*   Updated: 2020/02/09 22:38:24 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_H_H
#	define FT_H_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_map
{
	int		size;
	char	**key;
	char	**value;
}				t_map;
extern t_map	g_map;
extern int		g_file;
extern int		g_is_blank;
extern int		g_flag;

int				set_g_map(char *dict_name);
void			get_free(char *key_num);
void			find_new_dictionary(char *argv[], char *key_num);

int				check_valid_number(char *str);
int				get_trimed_length(char *str);
char			*get_trimed_number(char *str);
int				get_map_size(char *dict_name);

int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(char *src, int start, int end);
void			ft_putstr(char *str);

int				allocate_key_array
				(char c, int *is_colon, int *index, int *key_size);
int				get_key_array(char *dict_name);
void			fill_key(char c, int *is_colon, int *index, int *i);
int				set_key_array(char *dict_name);
int				check_valid_value(void);

int				allocate_value_array
				(char c, int *is_colon, int *index, int *value_size);
int				get_value_array(char *dict_name);
void			fill_value(char c, int *is_colon, int *index, int *i);
int				set_value_array(char *dict_name);
void			trim_value_array(void);

void			get_result(char *value);
char			*make_digit(int size);

void			print_one(char *str);
void			print_ten(char *str);
void			print_hundread(char *str);
void			print_num(char *value, int ref);
void			print_digit(int ref);

#	endif
