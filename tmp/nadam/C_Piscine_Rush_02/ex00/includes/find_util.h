/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_util.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jushin <jushin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 20:50:27 by jushin            #+#    #+#             */
/*   Updated: 2020/02/09 20:50:40 by jushin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_UTIL_H
# define FIND_UTIL_H

int		find_in_dict(t_dict **hash, char *to_find);
int		split_by_digit(char *to_find);
void	put_by_digit(char **arr, char *str, int size);
void	print_digit(t_dict **hash, int	digit);
int		num_max_len(t_dict **hash);

#endif
