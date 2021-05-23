/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:58:05 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 11:55:29 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

float	random_float(void)
{
	return ((float)rand() / (float)RAND_MAX);
}

float	random_float_(float min, float max)
{
	return (min + (max - min) * random_float());
}
