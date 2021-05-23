/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 16:27:11 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:06:13 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

static t_quaternion	convert(t_rotation angle)
{
	t_quaternion	q;
	t_vector		radians;
	t_vector		cos;
	t_vector		sin;

	radians = get(degrees_to_radians, &angle);
	radians = divide(radians, 2);
	cos = get(cosf, &radians);
	sin = get(sinf, &radians);
	q.w = cos.x * cos.y * cos.z + sin.x * sin.y * sin.z;
	q.v.x = sin.x * cos.y * cos.z - cos.x * sin.y * sin.z;
	q.v.y = cos.x * sin.y * cos.z + sin.x * cos.y * sin.z;
	q.v.z = cos.x * cos.y * sin.z - sin.x * sin.y * cos.z;
	return (q);
}

t_vector			rotate(t_vector v, t_rotation angle)
{
	t_quaternion	q;
	t_vector		v_;
	t_vector		t;

	v_ = v;
	if (has_value(&angle))
	{
		q = convert(angle);
		t = cross(multiply(q.v, 2), v);
		v_ = add(v_, multiply(t, q.w));
		v_ = add(v_, cross(q.v, t));
	}
	return (v_);
}

t_rotation			get_angle(t_vector v)
{
	t_rotation		angle;

	angle.x = atan2f(v.z, v.y);
	angle.y = 0;
	angle.z = atan2f(v.x, v.z);
	angle = get(radians_to_degrees, &angle);
	return (angle);
}
