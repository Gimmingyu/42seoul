/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:37:20 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:51:29 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_bool	add_box(t_scene *scene, char **c)
{
	t_point		center;
	t_color		color;
	t_rotation	angle;
	t_object	*box;
	t_vector	size;

	if (is_(c, "bo"))
	{
		check_spaces(c);
		center = get_coordinate(c);
		check_spaces(c);
		angle = get_angle(get_orientation(c));
		check_spaces(c);
		size = get_coordinate(c);
		check_spaces(c);
		color = get_color(c);
		box = box_(center, size, angle, get_material(color, c));
		push(&scene->world, box);
		return (true);
	}
	return (false);
}

t_bool	add_pyramid(t_scene *scene, char **c)
{
	t_point		center;
	t_color		color;
	t_rotation	angle;
	t_object	*py;
	t_vector	size;

	if (is_(c, "py"))
	{
		check_spaces(c);
		center = get_coordinate(c);
		check_spaces(c);
		angle = get_angle(get_orientation(c));
		check_spaces(c);
		size.x = get_float(c);
		check_spaces(c);
		size.y = get_float(c);
		check_spaces(c);
		color = get_color(c);
		py = pyramid_(center, vector_(size.x, size.x, size.y), angle,
				get_material(color, c));
		join(&scene->world, py, 5);
		return (true);
	}
	return (false);
}
