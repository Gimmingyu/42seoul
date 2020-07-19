/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 20:50:32 by jipark            #+#    #+#             */
/*   Updated: 2020/02/02 21:51:54 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_BACKTRACKING_H
#	define FT_BACKTRACKING_H

void	dfs(int **map_arr, int row, int col);
void	print_map(int **map_arr);
void	check_required_conditions(int **map_arr, int row, int col);

#	endif
