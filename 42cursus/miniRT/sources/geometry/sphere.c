/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:29:00 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:02:04 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_object	*sphere_(t_point center, float radius, t_material material)
{
	t_hittable	h;
	t_sphere	*s;

	h.geometry = _sphere;
	h.material = material;
	h.pointer = malloc(sizeof(t_sphere));
	s = h.pointer;
	if (!s)
		quit(MALLOC, "sphere_()");
	s->center = center;
	s->radius = radius;
	return (object_(h));
}

t_range		range_(float min, float max)
{
	t_range	range;

	range.min = min;
	range.max = max;
	return (range);
}

t_bool		hit_sphere(t_sphere *s, t_ray *r, t_range range, t_hit *contact)
{
	t_vector	oc;
	float		a;
	float		half_b;
	float		c;
	float		distance;

	oc = subtract(r->origin, s->center);
	a = dot(r->direction, r->direction);
	half_b = dot(oc, r->direction);
	c = dot(oc, oc) - s->radius * s->radius;
	distance = solve(a, half_b, c, range);
	if (distance != distance)
		return (false);
	contact->distance = distance;
	contact->point = at(r, distance);
	set_face_normal(contact, r,
		divide(subtract(contact->point, s->center), s->radius));
	return (true);
}
