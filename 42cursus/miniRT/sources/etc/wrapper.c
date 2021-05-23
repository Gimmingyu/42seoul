/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:01:24 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:45:50 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	clear(void)
{
	t_scene	*scene;

	scene = scene_();
	mlx_clear_window(scene->graphics, scene->window);
}

void	get_screen_size(int *width, int *height)
{
	mlx_get_screen_size(scene_()->graphics, width, height);
}

void	put(int x, int y, int color)
{
	t_scene	*scene;

	scene = scene_();
	mlx_pixel_put(scene->graphics, scene->window, x, y, color);
	(void)x;
	(void)y;
	(void)color;
}

void	init(void)
{
	t_scene	*scene;

	scene = scene_();
	window(scene->width, scene->height, "miniRT");
	init_();
}

void	loop(void)
{
	t_scene	*scene;

	scene = scene_();
	check_closed();
	mlx_hook(scene->window, KEYPRESS, 0, handle_key, NULL);
	mlx_hook(scene->window, MOUSEPRESS, 0, handle_mouse, NULL);
	mlx_loop_hook(scene->graphics, loop_, NULL);
	mlx_loop(scene->graphics);
}
