/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:36:42 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:50:51 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

static t_bool	is_moving(int key)
{
	return (key == W || key == UP
		|| key == S || key == DOWN
		|| key == A || key == LEFT
		|| key == D || key == RIGHT);
}

void			refresh(t_scene *scene)
{
	scene->camera[scene->current] = camera_(scene->setup[scene->current]);
	scene->depth = 10;
	scene->samples = 1;
	scene->accumulated = 1;
	reset(scene->raw, scene->width, scene->height);
	record();
	show(scene->screen, scene->width, scene->height);
}

void			switch_camera(t_scene *scene, int key)
{
	const int	last = scene->camera_count - 1;

	if (key == Q || key == E)
	{
		if (key == Q)
		{
			if (scene->current > 0)
				scene->current--;
			else
				scene->current = last;
		}
		else
		{
			if (scene->current < last)
				scene->current++;
			else
				scene->current = 0;
		}
		refresh(scene);
	}
}

int				handle_key(int key)
{
	int			i;
	t_scene		*scene;
	t_setup		*setup;

	scene = scene_();
	if (key == ESC)
		quit(SUCCESS, "");
	if (is_moving(key))
	{
		i = scene->current;
		setup = &scene->setup[i];
		if (key == W || key == UP)
			setup->origin = add(setup->origin, scene->camera[i].up);
		else if (key == S || key == DOWN)
			setup->origin = subtract(setup->origin, scene->camera[i].up);
		else if (key == A || key == LEFT)
			setup->origin = subtract(setup->origin, scene->camera[i].right);
		else if (key == D || key == RIGHT)
			setup->origin = add(setup->origin, scene->camera[i].right);
		setup->focus = length(subtract(setup->origin, setup->target));
		refresh(scene);
	}
	else
		switch_camera(scene, key);
	return (key);
}
