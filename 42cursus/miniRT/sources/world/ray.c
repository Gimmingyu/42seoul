/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:39:55 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:08:54 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_ray		ray_(t_point origin, t_vector direction)
{
	t_ray	r;

	r.origin = origin;
	r.direction = direction;
	return (r);
}

t_point		at(t_ray *r, float scalar)
{
	return (add(r->origin, multiply(r->direction, scalar)));
}

static void	shake(t_scene *scene, float *x, float *y)
{
	const int	width = scene->width;
	const int	height = scene->height;

	*x = (*x + random_float()) / (width - 1);
	*y = (height - *y + random_float()) / (height - 1);
}

t_ray		get_ray(t_camera *c, int x, int y)
{
	t_vector	direction;
	t_vector	bokeh;
	t_vector	offset;
	float		x_;
	float		y_;

	x_ = x;
	y_ = y;
	shake(scene_(), &x_, &y_);
	bokeh = multiply(random_in_unit_disk(), c->lens_radius);
	offset = multiply(c->right, bokeh.x);
	offset = add(offset, multiply(c->up, bokeh.y));
	direction = add(c->lower_left, multiply(c->horizontal, x_));
	direction = add(direction, multiply(c->vertical, y_));
	direction = subtract(direction, c->origin);
	direction = subtract(direction, offset);
	return (ray_(add(c->origin, offset), direction));
}

#ifndef RAINBOW

t_color		color_ray(t_ray *r, t_scene *s, t_object *world, int depth)
{
	t_hit		contact;
	t_ray		scattered;
	t_color		emitted;
	t_color		attenuation;
	t_color		color;

	if (depth <= 0)
		return (color_(0, 0, 0));
	if (!hit(world, r, range_(0.1, INFINITY), &contact))
		return (s->background);
	emitted = contact.material.emittor;
	if (!scatter(r, &contact, &attenuation, &scattered))
		return (emitted);
	color = s->ambient_light;
	color = add(color, color_ray(&scattered, s, world, depth - 1));
	return (multiply_(add(emitted, multiply_(attenuation, color)), s->filter));
}

#endif
