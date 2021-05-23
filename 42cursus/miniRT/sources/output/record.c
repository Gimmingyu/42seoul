/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:13:55 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:11:05 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

void	record_samples(int x, int y)
{
	t_ray	r;
	t_scene	*s;
	int		i;

	s = scene_();
	i = 0;
	while (i++ < s->samples)
	{
		r = get_ray(&s->camera[s->current], x, y);
		s->raw[x][y] = add(s->raw[x][y], color_ray(&r, s, s->world, s->depth));
	}
}

void	record_(t_screen screen, t_raw pixels, int samples)
{
	t_pixel		pixel;
	t_color		rgb;
	float		scale;
	int			x;
	int			y;

	scale = 1.0 / samples;
	x = scene_()->width;
	while (x--)
	{
		y = scene_()->height;
		while (y--)
		{
			rgb = pixels[x][y];
			rgb.x = clamp_float(sqrtf(scale * rgb.x), 0, 1);
			rgb.y = clamp_float(sqrtf(scale * rgb.y), 0, 1);
			rgb.z = clamp_float(sqrtf(scale * rgb.z), 0, 1);
			pixel.r = (t_byte)(rgb.x * 255);
			pixel.g = (t_byte)(rgb.y * 255);
			pixel.b = (t_byte)(rgb.z * 255);
			screen[x][y] = pixel;
		}
	}
}

#ifndef BONUS

void	record(void)
{
	t_scene	*scene;
	int		x;
	int		y;

	scene = scene_();
	x = scene->width;
	while (x--)
	{
		y = scene->height;
		while (y--)
			record_samples(x, y);
	}
	record_(scene->screen, scene->raw, scene->accumulated);
}

#endif
