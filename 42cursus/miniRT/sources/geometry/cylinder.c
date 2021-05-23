/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:25:58 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:04:48 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_object	*cylinder_(t_circle end, float height, t_rotation angle,
	t_material material)
{
	t_hittable	h;
	t_cylinder	*c;

	end.normal = rotate(end.normal, angle);
	h.geometry = _cylinder;
	h.material = material;
	h.pointer = malloc(sizeof(t_cylinder));
	c = h.pointer;
	if (!c)
		quit(MALLOC, "cylinder_()");
	c->height = fabsf(height);
	c->end[0] = end;
	end.center = add(end.center, multiply(end.normal, height));
	c->end[1] = end;
	return (object_(h));
}

t_bool		hit_end(t_circle *c, t_ray *r, t_range range, t_hit *contact)
{
	t_hit	just_hit;

	if (hit_circle(c, r, range, &just_hit)
		&& just_hit.distance < contact->distance)
	{
		*contact = just_hit;
		return (true);
	}
	return (false);
}

float		get_distance(t_cylinder *cy, t_ray *r, t_range range)
{
	t_vector	a_;
	t_vector	b_;
	float		a;
	float		half_b;
	float		c;

	a_ = cross(r->direction, cy->end->normal);
	a = dot(a_, a_);
	b_ = subtract(r->origin, cy->end->center);
	b_ = cross(b_, cy->end->normal);
	half_b = dot(a_, b_);
	c = dot(b_, b_) - powf(cy->end->radius, 2)
		* dot(cy->end->normal, cy->end->normal);
	return (solve(a, half_b, c, range));
}

t_bool		hit_cylinder(t_cylinder *cy,
		t_ray *r, t_range range, t_hit *contact)
{
	t_vector	outward;
	t_point		point;
	float		distance;
	float		height;
	t_bool		is_hit;

	contact->distance = range.max;
	is_hit = hit_end(&cy->end[0], r, range, contact);
	is_hit = hit_end(&cy->end[1], r, range, contact) || is_hit;
	distance = get_distance(cy, r, range);
	if (distance == distance && distance < contact->distance)
	{
		point = at(r, distance);
		height = dot(cy->end->normal, subtract(point, cy->end->center));
		if (is_in(height, range_(0, cy->height)))
		{
			contact->distance = distance;
			contact->point = point;
			outward = subtract(point,
					add(cy->end->center, multiply(cy->end->normal, height)));
			set_face_normal(contact, r, normalize(outward));
			is_hit = true;
		}
	}
	return (is_hit);
}
