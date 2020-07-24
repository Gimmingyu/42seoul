/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 04:30:07 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/19 14:22:31 by kyekim           ###   ########.fr       */
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
