/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:52:38 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:54:57 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "math/vector.h"

void			init_(void)
{
	t_scene	*scene;

	scene = scene_();
	scene->raw = raw_(scene->width, scene->height);
	scene->screen = screen_(scene->width, scene->height);
	if (scene->is_saving)
	{
		scene->depth = scene->depth_limit;
		scene->samples = scene->samples_limit;
		scene->accumulated = scene->samples_limit;
		record();
		save(scene->screen);
		quit(SUCCESS, "");
	}
	record();
	show(scene->screen, scene->width, scene->height);
}

int				loop_(void)
{
	t_scene	*scene;

	scene = scene_();
	if (scene->depth < scene->depth_limit
		|| scene->samples < scene->samples_limit)
	{
		if (scene->depth < scene->depth_limit)
		{
			reset(scene->raw, scene->width, scene->height);
			++scene->depth;
		}
		else
			scene->accumulated += ++scene->samples;
		record();
		show(scene->screen, scene->width, scene->height);
	}
	return (0);
}

static t_bool	is_same(char *a, char *b)
{
	while (*a && *b && *a++ == *b++)
		;
	return (*a == *b);
}

int				main(int argc, char *argv[])
{
	t_scene	*scene;

	scene = scene_();
	if (argc == 2 || argc == 3)
	{
		if (argc == 3)
		{
			if (!is_same("--save", argv[2]))
				quit(ERROR, "main()");
			scene->is_saving = true;
		}
		read_file(argv[1]);
		init();
		loop();
	}
}
