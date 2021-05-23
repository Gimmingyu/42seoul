/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:37:05 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:46:54 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_bool	add_sphere(t_scene *scene, char **c)
{
	t_point		center;
	t_color		color;
	t_object	*sphere;
	float		radius;

	if (is_(c, "sp"))
	{
		check_spaces(c);
		center = get_coordinate(c);
		check_spaces(c);
		radius = get_float(c) / 2;
		check_spaces(c);
		color = get_color(c);
		sphere = sphere_(center, radius, get_material(color, c));
		push(&scene->world, sphere);
		return (true);
	}
	return (false);
}

t_bool	add_plane(t_scene *scene, char **c)
{
	t_point		center;
	t_color		color;
	t_vector	normal;
	t_object	*plane;

	if (is_(c, "pl"))
	{
		check_spaces(c);
		center = get_coordinate(c);
		check_spaces(c);
		normal = normalize(get_orientation(c));
		check_spaces(c);
		color = get_color(c);
		plane = plane_(center, normal, get_material(color, c));
		push(&scene->world, plane);
		return (true);
	}
	return (false);
}

t_bool	add_square(t_scene *scene, char **c)
{
	t_point		center;
	t_color		color;
	t_rotation	angle;
	t_object	*square;
	float		width;

	if (is_(c, "sq"))
	{
		check_spaces(c);
		center = get_coordinate(c);
		check_spaces(c);
		angle = get_angle(get_orientation(c));
		check_spaces(c);
		width = get_float(c);
		check_spaces(c);
		color = get_color(c);
		square = rectangle_(center, vector_(width, width, 0), angle,
				get_material(color, c));
		push(&scene->world, square);
		return (true);
	}
	return (false);
}

t_bool	add_cylinder(t_scene *scene, char **c)
{
	t_circle	end;
	t_color		color;
	t_object	*cylinder;
	float		height;

	if (is_(c, "cy"))
	{
		check_spaces(c);
		end.center = get_coordinate(c);
		check_spaces(c);
		end.normal = normalize(get_orientation(c));
		check_spaces(c);
		end.radius = get_float(c) / 2;
		check_spaces(c);
		height = get_float(c);
		check_spaces(c);
		color = get_color(c);
		cylinder = cylinder_(end, height, rotation_(0, 0, 0),
				get_material(color, c));
		push(&scene->world, cylinder);
		return (true);
	}
	return (false);
}

t_bool	add_triangle(t_scene *scene, char **c)
{
	t_point		p[3];
	t_color		color;
	t_object	*triangle;

	if (is_(c, "tr"))
	{
		check_spaces(c);
		p[0] = get_coordinate(c);
		check_spaces(c);
		p[1] = get_coordinate(c);
		check_spaces(c);
		p[2] = get_coordinate(c);
		check_spaces(c);
		color = get_color(c);
		triangle = triangle_(p[0], p[1], p[2], get_material(color, c));
		push(&scene->world, triangle);
		return (true);
	}
	return (false);
}
