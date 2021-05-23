/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rectangle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:28:37 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:05:22 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_object		*rectangle_(
		t_point center, t_vector size, t_vector angle, t_material material)
{
	t_hittable	h;
	t_rectangle	*r;
	t_point		origin;
	t_vector	local[2];
	t_vector	edges[2];

	h.geometry = _rectangle;
	h.material = material;
	h.pointer = malloc(sizeof(t_rectangle));
	r = h.pointer;
	if (!r)
		quit(MALLOC, "rectangle_()");
	local[X] = rotate(vector_(1, 0, 0), angle);
	local[Y] = rotate(vector_(0, 0, 1), angle);
	edges[X] = multiply(local[X], size.x);
	edges[Y] = multiply(local[Y], size.y);
	origin = subtract(center, divide(edges[X], 2));
	origin = subtract(origin, divide(edges[Y], 2));
	r->p[0] = origin;
	r->p[1] = add(origin, edges[X]);
	r->p[2] = add(r->p[1], edges[Y]);
	r->p[3] = add(origin, edges[Y]);
	return (object_(h));
}

static t_bool	is_inside(t_point point, t_point *edges, t_vector n, t_point *p)
{
	return (dot(cross(edges[0], subtract(point, p[0])), n) >= 0
		&& dot(cross(edges[1], subtract(point, p[1])), n) >= 0
		&& dot(cross(edges[2], subtract(point, p[2])), n) >= 0
		&& dot(cross(edges[3], subtract(point, p[3])), n) >= 0);
}

t_bool			hit_rectangle(t_rectangle *rect, t_ray *r, t_range range,
	t_hit *contact)
{
	t_plane		p;
	t_vector	edges[4];
	t_point		point;
	float		distance;
	float		nd;

	edges[0] = subtract(rect->p[1], rect->p[0]);
	edges[1] = subtract(rect->p[2], rect->p[0]);
	p.normal = normalize(cross(edges[0], edges[1]));
	p.distance = dot(p.normal, rect->p[0]);
	nd = dot(p.normal, r->direction);
	distance = p.distance - dot(p.normal, r->origin);
	distance /= nd;
	if (!nd || !is_in(distance, range))
		return (false);
	edges[1] = subtract(rect->p[2], rect->p[1]);
	edges[2] = subtract(rect->p[3], rect->p[2]);
	edges[3] = subtract(rect->p[0], rect->p[3]);
	point = at(r, distance);
	if (!is_inside(point, edges, p.normal, rect->p))
		return (false);
	contact->distance = distance;
	contact->point = at(r, distance);
	set_face_normal(contact, r, p.normal);
	return (true);
}

#ifndef BONUS

t_bool			hit_box(t_box *box, t_ray *r, t_range range, t_hit *contact)
{
	(void)box;
	(void)r;
	(void)range;
	(void)contact;
	return (false);
}

#endif
