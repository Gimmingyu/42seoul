/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:35:44 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:46:15 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_color		get_color(char **c)
{
	t_color	color;
	int		r;
	int		g;
	int		b;

	r = get_int(UNSIGNED, c);
	check(c, ',');
	g = get_int(UNSIGNED, c);
	check(c, ',');
	b = get_int(UNSIGNED, c);
	if (0 > r || r > 255 || 0 > g || g > 255 || 0 > b || b > 255)
		quit(MISCONFIG, "get_color()");
	color.x = (float)r / 255;
	color.y = (float)g / 255;
	color.z = (float)b / 255;
	return (color);
}

t_point		get_coordinate(char **c)
{
	t_point	coordinate;

	coordinate.x = get_float(c);
	check(c, ',');
	coordinate.y = get_float(c);
	check(c, ',');
	coordinate.z = get_float(c);
	return (coordinate);
}

t_vector	get_orientation(char **c)
{
	t_vector	v;

	v = get_coordinate(c);
	if (!is_in(v.x, range_(-1, 1))
		|| !is_in(v.y, range_(-1, 1))
		|| !is_in(v.z, range_(-1, 1)))
		quit(MISCONFIG, "get_orientation()");
	return (v);
}
