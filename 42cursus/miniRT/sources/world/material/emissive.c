/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emissive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:38:19 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 11:38:24 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"
#include "../../math/vector.h"

t_material	emissive_(t_color rgb)
{
	t_material	light;

	light = material_(emissive, color_(0, 0, 0), false, false);
	light.emittor = rgb;
	return (light);
}
