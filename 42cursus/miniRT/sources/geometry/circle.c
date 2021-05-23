/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:16:59 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:02:28 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_circle		circle__(t_point center, float radius)
{
	t_circle	c;

	c.center = center;
	c.radius = radius;
	c.normal = vector_(0, 1, 0);
	return (c);
}

t_object		*circle_(
		t_point center, float radius, t_rotation angle, t_material material)
{
	t_hittable	h;
	t_circle	*c;

	h.geometry = _circle;
	h.material = material;
	h.pointer = malloc(sizeof(t_circle));
	c = h.pointer;
	if (!c)
		quit(MALLOC, "circle_()");
	c->center = center;
	c->normal = rotate(vector_(0, 1, 0), angle);
	c->radius = radius;
	return (object_(h));
}

static t_bool	is_inside(t_point point, t_circle *c)
{
	return (length(subtract(point, c->center)) <= c->radius);
}

t_bool			hit_circle(t_circle *c, t_ray *r, t_range range, t_hit *contact)
{
	t_plane		p;
	t_point		point;
	float		distance;

	p.normal = c->normal;
	p.distance = dot(p.normal, c->center);
	distance = p.distance - dot(p.normal, r->origin);
	distance /= dot(p.normal, r->direction);
	if (!is_in(distance, range) || fabsf(distance) < range.min)
		return (false);
	point = at(r, distance);
	if (!is_inside(point, c))
		return (false);
	contact->distance = distance;
	contact->point = at(r, distance);
	set_face_normal(contact, r, p.normal);
	return (true);
}
