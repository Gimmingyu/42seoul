/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:41:38 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:10:10 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_scene	*scene_(void)
{
	static t_scene	scene;

	if (!scene.samples)
	{
		scene.depth_limit = 12;
		scene.samples_limit = 20;
		scene.depth = 10;
		scene.samples = 1;
		scene.accumulated = 1;
		scene.width = 480;
		scene.height = 480;
		scene.filter = color_(1, 1, 1);
	}
	return (&scene);
}
