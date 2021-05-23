/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pyramid_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:28:16 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/09 13:28:18 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_object	*pyramid_(
		t_point center, t_vector size, t_vector angle, t_material material)
{
	t_object	*py;
	t_rectangle	*r;

	push(&py, rectangle_(center, size, angle, material));
	r = py->object.pointer;
	center = add(center, multiply(rotate(vector_(0, 1, 0), angle), size.z));
	push(&py, triangle_(center, r->p[0], r->p[1], material));
	push(&py, triangle_(center, r->p[1], r->p[2], material));
	push(&py, triangle_(center, r->p[2], r->p[3], material));
	push(&py, triangle_(center, r->p[3], r->p[0], material));
	return (py);
}
