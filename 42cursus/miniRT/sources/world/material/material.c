/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:36:59 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:09:11 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include "../../math/vector.h"

t_material	material_(t_surface s, t_color c, float f, float ir)
{
	t_material	m;

	m.surface = s;
	m.albedo = c;
	m.fuzz = f;
	m.ir = ir;
	m.emittor = color_(0, 0, 0);
	return (m);
}

t_bool		plain_scatter(t_hit *contact, t_color *attenuation, t_ray *out)
{
	*out = ray_(contact->point, contact->normal);
	*attenuation = contact->material.albedo;
	return (true);
}

t_bool		scatter(t_ray *in, t_hit *contact, t_color *attenuation, t_ray *out)
{
	if (contact->material.surface == metal)
		return (metal_scatter(in, contact, attenuation, out));
	if (contact->material.surface == lambertian)
		return (lambertian_scatter(contact, attenuation, out));
	if (contact->material.surface == dielectric)
		return (dielectric_scatter(in, contact, attenuation, out));
	if (contact->material.surface == emissive)
		return (false);
	return (plain_scatter(contact, attenuation, out));
}
