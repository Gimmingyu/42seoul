/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:01:16 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:06:26 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "vector.h"

t_vector	negate(t_vector v)
{
	return (vector_(-v.x, -v.y, -v.z));
}

float		dot(t_vector u, t_vector v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vector	cross(t_vector u, t_vector v)
{
	t_vector	v_;

	v_.x = u.y * v.z - u.z * v.y;
	v_.y = u.z * v.x - u.x * v.z;
	v_.z = u.x * v.y - u.y * v.x;
	return (v_);
}

float		length(t_vector v)
{
	return (sqrtf(dot(v, v)));
}

t_vector	normalize(t_vector v)
{
	return (divide(v, length(v)));
}
