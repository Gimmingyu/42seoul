/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:35:52 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:49:57 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_bool	set_resolution(t_scene *scene, char **c)
{
	static t_bool	done;
	int				screen_width;
	int				screen_height;

	if (is(c, 'R'))
	{
		if (done)
			quit(MISCONFIG, "set_resolution()");
		check_spaces(c);
		get_screen_size(&screen_width, &screen_height);
		scene->width = get_int(UNSIGNED, c);
		if (scene->width > screen_width)
			scene->width = screen_width;
		check_spaces(c);
		scene->height = get_int(UNSIGNED, c);
		if (scene->height > screen_height)
			scene->height = screen_height;
		done = true;
		return (true);
	}
	return (false);
}

t_bool	set_ambient(t_scene *scene, char **c)
{
	t_color			color;
	float			brightness;
	static t_bool	done;

	if (is(c, 'A'))
	{
		if (done)
			quit(MISCONFIG, "set_ambient()");
		check_spaces(c);
		brightness = get_float(c);
		if (!is_in(brightness, range_(0, 1)))
			quit(MISCONFIG, "set_ambient()");
		check_spaces(c);
		color = get_color(c);
		scene->ambient_light = multiply(color, brightness);
		done = true;
		return (true);
	}
	return (false);
}
