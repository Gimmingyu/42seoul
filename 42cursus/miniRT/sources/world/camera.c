/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:39:00 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 11:39:03 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_camera	camera_(t_setup s)
{
	t_camera	c;
	float		theta;
	float		view_height;
	float		view_width;

	theta = degrees_to_radians(s.fov);
	view_width = 2 * tanf(theta / 2);
	view_height = view_width / s.aspect_ratio;
	c.front = normalize(subtract(s.origin, s.target));
	c.right = cross(s.up, c.front);
	c.up = cross(c.front, c.right);
	c.origin = s.origin;
	c.horizontal = multiply(multiply(c.right, view_width), s.focus);
	c.vertical = multiply(multiply(c.up, view_height), s.focus);
	c.lower_left = subtract(c.origin, divide(c.horizontal, 2));
	c.lower_left = subtract(c.lower_left, divide(c.vertical, 2));
	c.lower_left = subtract(c.lower_left, multiply(c.front, s.focus));
	c.lens_radius = s.aperture / 2;
	return (c);
}
