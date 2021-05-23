/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:07:04 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:05:11 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_rectangle	side_(t_point origin, t_vector size[2])
{
	t_rectangle	r;

	r.p[0] = origin;
	r.p[1] = add(origin, size[X]);
	r.p[2] = add(r.p[1], size[Y]);
	r.p[3] = add(origin, size[Y]);
	return (r);
}

t_box		box__(t_point origin, t_vector edges[3])
{
	t_box		b;
	t_vector	xy[2];
	t_vector	yz[2];
	t_vector	xz[2];

	xy[0] = edges[X];
	xy[1] = edges[Y];
	yz[0] = edges[Y];
	yz[1] = edges[Z];
	xz[0] = edges[X];
	xz[1] = edges[Z];
	b.side[0] = side_(origin, xy);
	b.side[1] = side_(origin, yz);
	b.side[2] = side_(origin, xz);
	b.side[3] = side_(add(origin, edges[Z]), xy);
	b.side[4] = side_(add(origin, edges[X]), yz);
	b.side[5] = side_(add(origin, edges[Y]), xz);
	return (b);
}

t_object	*box_(t_point center, t_vector size, t_rotation angle,
	t_material material)
{
	t_hittable	h;
	t_box		*b;
	t_point		origin;
	t_vector	local[3];
	t_vector	edges[3];

	local[X] = rotate(vector_(1, 0, 0), angle);
	local[Y] = rotate(vector_(0, 1, 0), angle);
	local[Z] = cross(local[X], local[Y]);
	edges[X] = multiply(local[X], size.x);
	edges[Y] = multiply(local[Y], size.y);
	edges[Z] = multiply(local[Z], size.z);
	origin = subtract(center, divide(edges[X], 2));
	origin = subtract(origin, divide(edges[Y], 2));
	origin = subtract(origin, divide(edges[Z], 2));
	h.geometry = _box;
	h.material = material;
	h.pointer = malloc(sizeof(t_box));
	b = h.pointer;
	if (!b)
		quit(MALLOC, "box_()");
	*b = box__(origin, edges);
	return (object_(h));
}

t_bool		hit_box(t_box *b, t_ray *r, t_range range, t_hit *contact)
{
	t_hit	just_hit;
	int		i;
	t_bool	is_hit;

	is_hit = false;
	i = 0;
	contact->distance = range.max;
	while (i < 6)
	{
		if (hit_rectangle(&b->side[i++], r, range, &just_hit)
			&& just_hit.distance < contact->distance)
		{
			*contact = just_hit;
			is_hit = true;
		}
	}
	return (is_hit);
}
