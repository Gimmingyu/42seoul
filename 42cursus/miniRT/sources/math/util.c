/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:53:29 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/11 16:54:08 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	degrees_to_radians(float degrees)
{
	return (degrees * M_PI / 180);
}

float	radians_to_degrees(float radians)
{
	return (radians * 180 / M_PI);
}

float	clamp_float(float x, float min, float max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

t_bool	is_in(float n, t_range range)
{
	return (range.min <= n && n <= range.max);
}

float	solve(float a, float half_b, float c, t_range range)
{
	float	root;
	float	sqrt_d;
	float	discriminant;

	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (NAN);
	sqrt_d = sqrtf(discriminant);
	root = (-half_b - sqrt_d) / a;
	if (!is_in(root, range))
	{
		root = (-half_b + sqrt_d) / a;
		if (!is_in(root, range))
			return (NAN);
	}
	return (root);
}
