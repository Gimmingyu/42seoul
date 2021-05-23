/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:57:51 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 11:56:06 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "vector.h"

t_vector	multiply_(t_vector v, t_vector u)
{
	return (vector_(v.x * u.x, v.y * u.y, v.z * u.z));
}

t_vector	multiply(t_vector v, float t)
{
	return (vector_(v.x * t, v.y * t, v.z * t));
}

t_vector	divide(t_vector v, float t)
{
	return (multiply(v, 1 / t));
}

t_vector	add(t_vector u, t_vector v)
{
	return (vector_(u.x + v.x, u.y + v.y, u.z + v.z));
}

t_vector	subtract(t_vector u, t_vector v)
{
	return (vector_(u.x - v.x, u.y - v.y, u.z - v.z));
}
