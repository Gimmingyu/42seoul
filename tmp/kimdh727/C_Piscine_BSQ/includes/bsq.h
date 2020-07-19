/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 00:09:13 by donghwki          #+#    #+#             */
/*   Updated: 2020/02/12 22:37:44 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

int				g_flag;

typedef	struct	s_bsq_map
{
	int		row;
	int		col;
	int		**map;

	char	empty;
	char	obstacle;
	char	full;

	int		max;
	int		max_row;
	int		max_col;
}				t_bsq_map;

void			bsq(int argc, char *argv[]);
void			solve_bsq(char **map_data);
void			free_map(t_bsq_map *map);
void			map_memory(t_bsq_map *map);
void			map_set(t_bsq_map *map, char **map_file);

char			*make_buf(int fd);
int				check_info(char *info);
char			**read_map(char *buf);

void			ft_min(int *min, int *cmp);
int				ft_is_max(int *max, int *cmp);
int				in_the_full(t_bsq_map *map, int row, int col);
int				is_printable(char *str);
int				is_map(char *str, char empty, char obstacle);

void			map_init(t_bsq_map *map, char *map_info, int row, int col);
void			max_check(t_bsq_map *map);
void			calc_map(t_bsq_map *map, int row, int col);
void			solve_map(t_bsq_map *map);
void			pirnt_map(t_bsq_map *map);

void			free_split(int cnt, char **split);
char			**ft_split(char *str, char *charset);

int				ft_strlen(char *str);
int				ft_strarrlen(char **strarr);
int				ft_atoi(char *str);
char			*ft_strdup(char *str, int st, int en, int size);
char			*ft_strcpy(char *dest, char *src);

int				empty_line_check(char *buf);
int				same_row_len(char **map_file, int row);
int				print_able_map(char **map_file);

#endif
