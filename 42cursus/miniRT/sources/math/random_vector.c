/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:04:47 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 12:02:02 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "vector.h"

t_vector	random_vector(void)
{
	return (vector_(random_float(), random_float(), random_float()));
}

t_vector	random_vector_(float min, float max)
{
	t_vector	v;

	v.x = random_float_(min, max);
	v.y = random_float_(min, max);
	v.z = random_float_(min, max);
	return (v);
}

t_vector	random_in_unit_sphere(void)
{
	t_vector	v;

	while (true)
	{
		v = random_vector_(-1, 1);
		if (dot(v, v) < 1)
			return (v);
	}
}

t_vector	random_in_unit_disk(void)
{
	t_vector	v;

	while (true)
	{
		v = vector_(random_float_(-1, 1), random_float_(-1, 1), 0);
		if (dot(v, v) < 1)
			return (v);
	}
}

t_vector	random_unit_vector(void)
{
	return (normalize(random_in_unit_sphere()));
}
