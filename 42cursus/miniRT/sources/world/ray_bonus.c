/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:40:10 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:07:42 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

#ifdef RAINBOW

t_color	color_ray(t_ray *r, t_scene *s, t_object *world, int depth)
{
	t_hit		contact;

	(void)s;
	if (depth <= 0)
		return (color_(0, 0, 0));
	if (!hit(world, r, range_(0.4, INFINITY), &contact))
		return (color_(0.000, 0.000, 0.000));
	return (divide(add(vector_(1, 1, 1), contact.normal), 2));
}

#endif
