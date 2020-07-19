/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_location.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 21:49:46 by jipark            #+#    #+#             */
/*   Updated: 2020/02/02 21:53:56 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_VERIFY_LOCATION_H
#	define FT_VERIFY_LOCATION_H

int		is_possible_row(int **map_arr, int row, int col);
int		is_possible_col(int **map_arr, int row, int col);
int		compare_restriction(int first, int last, int row, int col);
int		check_row_exception(int **map_arr, int row);
int		check_col_exception(int **map_arr, int col);

#	endif
