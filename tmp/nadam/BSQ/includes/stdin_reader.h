/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_reader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:32:47 by jko               #+#    #+#             */
/*   Updated: 2020/02/12 21:53:04 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIN_READER_H
# define STDIN_READER_H

# include "map_reader.h"

char		**read_from_stdin(void);
t_map_info	*read_map_info_from_stdin(char *void_param);

#endif
