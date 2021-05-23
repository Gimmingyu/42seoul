/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:39:36 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:09:42 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_object		*object_(t_hittable object)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (new)
	{
		new->object = object;
		new->next = NULL;
	}
	return (new);
}

void			push(t_object **object, t_object *new)
{
	t_object	*temp;

	temp = *object;
	*object = new;
	(*object)->next = temp;
}

void			join(t_object **object, t_object *new, int count)
{
	t_object	*current;

	current = new;
	while (--count)
		current = current->next;
	current->next = *object;
	*object = new;
}

static t_bool	hit_(t_hittable *object, t_ray *r, t_range range,
	t_hit *contact)
{
	t_bool	is_hit;

	is_hit = false;
	if (object->geometry == _sphere)
		is_hit = hit_sphere(object->pointer, r, range, contact);
	else if (object->geometry == _rectangle)
		is_hit = hit_rectangle(object->pointer, r, range, contact);
	else if (object->geometry == _circle)
		is_hit = hit_circle(object->pointer, r, range, contact);
	else if (object->geometry == _box)
		is_hit = hit_box(object->pointer, r, range, contact);
	else if (object->geometry == _plane)
		is_hit = hit_plane(object->pointer, r, range, contact);
	else if (object->geometry == _triangle)
		is_hit = hit_triangle(object->pointer, r, range, contact);
	else if (object->geometry == _cylinder)
		is_hit = hit_cylinder(object->pointer, r, range, contact);
	else if (object->geometry == _spot)
		is_hit = hit_spot(object->pointer, r, range, contact);
	if (is_hit)
		contact->material = object->material;
	return (is_hit);
}

t_bool			hit(t_object *current, t_ray *r, t_range range, t_hit *contact)
{
	t_hit		just_hit;
	t_bool		is_hit;

	is_hit = false;
	contact->distance = range.max;
	while (current)
	{
		if (hit_(&current->object, r, range, &just_hit)
			&& just_hit.distance < contact->distance)
		{
			if (current->object.geometry == _spot)
				hit_spots(current->next, r, range, &just_hit);
			is_hit = true;
			*contact = just_hit;
		}
		current = current->next;
	}
	return (is_hit);
}
