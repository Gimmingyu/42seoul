/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 21:40:19 by jko               #+#    #+#             */
/*   Updated: 2020/02/10 22:45:37 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# include "map_reader.h"

char	check_len(char **map, int line_num);
char	check_chars(t_map_info *info);
char	is_map_char(t_map_info *info, char c);
char	check_only_chars(t_map_info *info);
char	is_valid_map(t_map_info *info);

#endif
