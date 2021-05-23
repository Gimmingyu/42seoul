/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:38:42 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:53:24 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_bool		set_filter(t_scene *scene, char **c)
{
	static t_bool	done;

	if (is(c, 'F'))
	{
		if (done)
			quit(MISCONFIG, "set_filter()");
		check_spaces(c);
		scene->filter = get_color(c);
		done = true;
		return (true);
	}
	return (false);
}

t_bool		set_background(t_scene *scene, char **c)
{
	static t_bool	done;

	if (is(c, 'B'))
	{
		if (done)
			quit(MISCONFIG, "set_background()");
		check_spaces(c);
		scene->background = get_color(c);
		done = true;
		return (true);
	}
	return (false);
}

t_material	get_material(t_color color, char **c)
{
	if (is(c, 'd'))
		return (dielectric_(color, 1.5));
	if (is(c, 'e'))
		return (emissive_(color));
	if (is(c, 'm'))
		return (metal_(color, 0));
	return (lambertian_(color));
}

t_bool		handle_line(t_scene *scene, char *line)
{
	if (!(set_resolution(scene, &line)
			|| set_ambient(scene, &line)
			|| set_background(scene, &line)
			|| set_filter(scene, &line)
			|| add_camera(scene, &line)
			|| add_light(scene, &line)
			|| add_sphere(scene, &line)
			|| add_plane(scene, &line)
			|| add_square(scene, &line)
			|| add_cylinder(scene, &line)
			|| add_triangle(scene, &line)
			|| add_box(scene, &line)
			|| add_pyramid(scene, &line)) || *line)
		return (false);
	else
		return (true);
}
