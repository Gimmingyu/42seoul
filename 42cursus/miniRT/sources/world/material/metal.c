/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:34:28 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/11 19:37:00 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include "../../math/vector.h"

t_material	metal_(t_color color, float fuzz)
{
	return (material_(metal, color, fuzz, false));
}

t_bool		metal_scatter(t_ray *in, t_hit *contact,
		t_color *attenuation, t_ray *out)
{
	t_vector	direction;
	t_vector	fuzz;

	direction = reflect(normalize(in->direction), contact->normal);
	fuzz = multiply(random_in_unit_sphere(), contact->material.fuzz);
	*out = ray_(contact->point, add(direction, fuzz));
	*attenuation = contact->material.albedo;
	return (dot(out->direction, contact->normal) > 0);
}
