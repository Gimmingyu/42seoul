/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:37:41 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:51:47 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_bool	is_pressed(int button)
{
	return (button == SCROLLUP || button == SCROLLDOWN);
}

int		handle_mouse(int button)
{
	int		i;
	t_scene	*scene;
	t_setup	*setup;

	scene = scene_();
	if (is_pressed(button))
	{
		i = scene->current;
		setup = &scene->setup[i];
		if (button == SCROLLUP)
			setup->origin = add(setup->origin, scene->camera[i].front);
		else if (button == SCROLLDOWN)
			setup->origin = subtract(setup->origin, scene->camera[i].front);
		setup->focus = length(subtract(setup->origin, setup->target));
		refresh(scene);
	}
	return (button);
}
