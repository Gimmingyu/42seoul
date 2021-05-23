/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:38:42 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:08:06 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include "../../math/vector.h"

float		reflectance(float cos, float ref_idx)
{
	float	r;

	r = (1 - ref_idx) / (1 + ref_idx);
	r = r * r;
	return (r + (1 - r) * powf((1 - cos), 5));
}

t_material	dielectric_(t_color color, float ir)
{
	return (material_(dielectric, color, false, ir));
}

t_bool		dielectric_scatter(t_ray *in, t_hit *contact, t_color *attenuation,
			t_ray *out)
{
	t_vector	direction;
	float		refraction_ratio;
	float		cos_theta;
	float		sin_theta;

	if (contact->front_face)
		refraction_ratio = 1 / contact->material.ir;
	else
		refraction_ratio = contact->material.ir;
	direction = normalize(in->direction);
	cos_theta = fminf(dot(negate(direction), contact->normal), 1);
	sin_theta = sqrtf(1 - cos_theta * cos_theta);
	if (refraction_ratio * sin_theta > 1
		|| reflectance(cos_theta, refraction_ratio) > random_float())
		direction = reflect(direction, contact->normal);
	else
		direction = refract(direction, contact->normal, refraction_ratio);
	*out = ray_(contact->point, direction);
	*attenuation = contact->material.albedo;
	return (true);
}
