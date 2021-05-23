/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:01:41 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:05:58 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "vector.h"

t_bool		near_zero(t_vector v)
{
	const float	s = 1e-8;

	return ((fabsf(v.x) < s) && (fabsf(v.y) < s) && (fabsf(v.z) < s));
}

t_vector	reflect(t_vector v, t_vector n)
{
	return (subtract(v, multiply(n, 2 * dot(v, n))));
}

t_vector	refract(t_vector uv, t_vector n, float eta_over_etaprime)
{
	float		cos_theta;
	t_vector	r_perpendi;
	t_vector	r_parallel;

	cos_theta = fminf(dot(negate(uv), n), 1);
	r_perpendi = multiply(add(uv, multiply(n, cos_theta)), eta_over_etaprime);
	r_parallel = multiply(n, -sqrtf(fabsf(1 - dot(r_perpendi, r_perpendi))));
	return (add(r_perpendi, r_parallel));
}

t_bool		has_value(t_vector *v)
{
	return (v->x || v->y || v->z);
}

t_vector	get(float (*f)(float), t_vector *u)
{
	t_vector	v;

	v.x = f(u->x);
	v.y = f(u->y);
	v.z = f(u->z);
	return (v);
}
