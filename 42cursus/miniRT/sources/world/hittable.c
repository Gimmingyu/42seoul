/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hittable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:39:17 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:06:52 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

void	set_face_normal(t_hit *contact, t_ray *ray, t_vector outward)
{
	contact->front_face = dot(ray->direction, outward) < 0;
	if (contact->front_face)
		contact->normal = outward;
	else
		contact->normal = negate(outward);
}
