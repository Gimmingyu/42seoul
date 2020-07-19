/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:44:13 by jipark            #+#    #+#             */
/*   Updated: 2020/02/02 21:47:47 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PROCESS_INPUT_H
#	define FT_PROCESS_INPUT_H

int		is_valid_number(void);
int		set_restriction_array(char *input);
int		**get_map_array(void);
void	init_restriction_array(void);

#	endif
