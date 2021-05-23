/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:34:22 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:04:22 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_object	*triangle_(t_point p0, t_point p1, t_point p2, t_material material)
{
	t_hittable	h;
	t_riangle	*t;

	h.geometry = _triangle;
	h.material = material;
	h.pointer = malloc(sizeof(t_riangle));
	t = h.pointer;
	if (!t)
		quit(MALLOC, "triangle_()");
	t->p[0] = p0;
	t->p[1] = p1;
	t->p[2] = p2;
	return (object_(h));
}

t_bool		is_inside(t_point point, t_point *edges, t_vector n, t_point *p)
{
	return (dot(cross(edges[0], subtract(point, p[0])), n) >= 0
		&& dot(cross(edges[1], subtract(point, p[1])), n) >= 0
		&& dot(cross(edges[2], subtract(point, p[2])), n) >= 0);
}

t_bool		hit_triangle(t_riangle *t, t_ray *r, t_range range, t_hit *contact)
{
	t_plane		p;
	t_vector	edges[3];
	t_point		point;
	float		distance;
	float		nd;

	edges[0] = subtract(t->p[1], t->p[0]);
	edges[1] = subtract(t->p[2], t->p[0]);
	p.normal = normalize(cross(edges[0], edges[1]));
	p.distance = dot(p.normal, t->p[0]);
	nd = dot(p.normal, r->direction);
	distance = p.distance - dot(p.normal, r->origin);
	distance /= nd;
	if (!nd || !is_in(distance, range))
		return (false);
	edges[1] = subtract(t->p[2], t->p[1]);
	edges[2] = subtract(t->p[0], t->p[2]);
	point = at(r, distance);
	if (!is_inside(point, edges, p.normal, t->p))
		return (false);
	contact->distance = distance;
	contact->point = at(r, distance);
	set_face_normal(contact, r, p.normal);
	return (true);
}
