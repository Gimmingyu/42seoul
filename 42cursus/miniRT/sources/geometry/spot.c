/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:32:02 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:04:38 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"
#define RADIUS 42

t_object	*spot_(t_light light)
{
	t_hittable	h;
	t_spot		*s;

	h.geometry = _spot;
	h.material = emissive_(multiply(light.color, light.brightness));
	h.pointer = malloc(sizeof(t_spot));
	s = h.pointer;
	if (!s)
		quit(MALLOC, "spot_()");
	s->light = light;
	return (object_(h));
}

t_bool		is_lit(t_point *p, t_light *light)
{
	static const float	radius_squared = RADIUS * RADIUS;
	t_vector			v;

	v = subtract(*p, light->center);
	return (dot(v, v) < radius_squared);
}

t_bool		hit_spot(t_spot *s, t_ray *r, t_range range, t_hit *contact)
{
	t_point		point;
	float		distance;

	distance = length(subtract(r->origin, s->light.center));
	point = at(r, distance);
	if (is_in(distance, range) && is_lit(&point, &s->light))
	{
		contact->distance = distance;
		contact->point = s->light.center;
		return (true);
	}
	return (false);
}

void		hit_spots(t_object *current, t_ray *r,
		t_range range, t_hit *contact)
{
	t_color	*emittor;

	while (current)
	{
		if (hit_spot(current->object.pointer, r, range, contact))
		{
			emittor = &contact->material.emittor;
			*emittor = add(*emittor, *emittor);
		}
		current = current->next;
	}
}
