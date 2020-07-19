/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 09:30:07 by jipark            #+#    #+#             */
/*   Updated: 2020/02/01 09:50:06 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_POINT_H
#	define FT_POINT_H

typedef struct	s_point
{
	int x;
	int y;
}				t_point;
void			set_point(t_point *point);
#	endif
