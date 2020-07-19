/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:22:22 by jipark            #+#    #+#             */
/*   Updated: 2020/02/02 21:46:59 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_MAIN_H
#	define FT_MAIN_H

#include <unistd.h>
#include <stdlib.h>

extern int		g_size;
extern int		g_map_cnt;
extern int		**g_row_restriction;
extern int		**g_col_restriction;
int				is_valid_input(char *input);
void			free_map_array(int **map_arr);
void			free_restriction_array(void);

#	endif
