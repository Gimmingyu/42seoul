/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:37:52 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:07:13 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include "../../math/vector.h"

t_material	lambertian_(t_color color)
{
	return (material_(lambertian, color, false, false));
}

t_bool		lambertian_scatter(t_hit *contact,
		t_color *attenuation, t_ray *out)
{
	t_vector	direction;

	direction = add(contact->normal, random_unit_vector());
	if (near_zero(direction))
		direction = contact->normal;
	*out = ray_(contact->point, direction);
	*attenuation = contact->material.albedo;
	return (true);
}
