/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:54:21 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/11 16:57:05 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "vector.h"

t_vector	vector_(float x, float y, float z)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_point		point_(float x, float y, float z)
{
	return (vector_(x, y, z));
}

t_color		color_(float r, float g, float b)
{
	return (vector_(r, g, b));
}

t_rotation	rotation_(float x, float y, float z)
{
	return (vector_(x, y, z));
}

void		update(t_vector *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}
