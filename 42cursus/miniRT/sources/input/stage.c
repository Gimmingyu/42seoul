/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:36:02 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:54:00 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

static void	initial_setup(t_scene *scene, t_setup *setup)
{
	setup->aperture = 0.2;
	setup->up = vector_(0, 1, 0);
	setup->aspect_ratio = (float)scene->width / (float)scene->height;
}

t_bool		add_camera(t_scene *scene, char **c)
{
	static t_setup	setup;

	if (!scene->camera_count)
		initial_setup(scene, &setup);
	if (**c && (*c)[1] != 'y' && is(c, 'c'))
	{
		check_spaces(c);
		if (scene->camera_count == MAX)
			quit(CAMERA_MAXOUT, "add_camera()");
		setup.origin = get_coordinate(c);
		check_spaces(c);
		setup.target = rotate(point_(0, 0, 0), get_angle(get_orientation(c)));
		check_spaces(c);
		setup.focus = length(subtract(setup.target, setup.origin));
		setup.fov = get_int(UNSIGNED, c);
		if (0 > setup.fov || setup.fov > 180)
			quit(MISCONFIG, "add_camera()");
		scene->setup[scene->camera_count] = setup;
		scene->camera[scene->camera_count++] = camera_(setup);
		return (true);
	}
	return (false);
}

t_bool		add_light(t_scene *scene, char **c)
{
	t_light	light;

	if (is(c, 'l'))
	{
		check_spaces(c);
		light.center = get_coordinate(c);
		check_spaces(c);
		light.brightness = get_float(c);
		if (!is_in(light.brightness, range_(0, 1)))
			quit(MISCONFIG, "add_light()");
		check_spaces(c);
		light.color = get_color(c);
		push(&scene->world, spot_(light));
		return (true);
	}
	return (false);
}
