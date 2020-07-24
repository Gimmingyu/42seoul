/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:58:16 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/23 08:40:17 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUF_SIZE 4096

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_map
{
	int		x;
	int		y;
	int		max_x;
	int		max_y;
	int		max;
	int		**map;
	char	empty;
	char	obst;
	char	full;
}					t_map;

void				print_error(void);
int					ft_atoi(char *str);
int					ft_strlen(char *str);
char				*cpy_str_except_newline(char *a, char *b);
t_map				file_to_struct(char *filename);
t_map				set_info(char *str);
t_map				set_map(int file, t_map info);
int					get_x_len(int file);
char				*get_info(char *filename);
int					ft_min(int a, int b, int c);
void				set_max(t_map *info, int i, int j);
void				find_square(t_map *info);
void				set_square(t_map *info);
void				max_one(t_map *info);
void				print_map(t_map *info);

#endif
