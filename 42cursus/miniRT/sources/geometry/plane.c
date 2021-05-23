/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:27:52 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:01:28 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_object	*plane_(t_point center, t_vector normal, t_material material)
{
	t_hittable	h;
	t_plane		*p;

	h.geometry = _plane;
	h.material = material;
	h.pointer = malloc(sizeof(t_plane));
	p = h.pointer;
	if (!p)
		quit(MALLOC, "plane_()");
	p->normal = normal;
	p->distance = length(center);
	return (object_(h));
}

t_bool		hit_plane(t_plane *p, t_ray *r, t_range range, t_hit *contact)
{
	float		nd;
	float		distance;

	nd = dot(p->normal, r->direction);
	distance = p->distance - dot(p->normal, r->origin);
	distance /= nd;
	if (!nd || !is_in(distance, range))
		return (false);
	contact->distance = distance;
	contact->point = at(r, distance);
	set_face_normal(contact, r, p->normal);
	return (true);
}
