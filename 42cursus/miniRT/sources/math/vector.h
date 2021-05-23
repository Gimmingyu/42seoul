/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:57:11 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/11 16:57:13 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "../minirt.h"
# include "random.h"

t_vector	vector_(float x, float y, float z);
void		update(t_vector *v, float x, float y, float z);
t_vector	negate(t_vector v);
t_bool		near_zero(t_vector v);
t_vector	multiply_(t_vector v, t_vector u);
t_vector	multiply(t_vector v, float t);
t_vector	divide(t_vector v, float t);
float		length(t_vector v);
t_vector	add(t_vector u, t_vector v);
t_vector	subtract(t_vector u, t_vector v);
float		dot(t_vector u, t_vector v);
t_vector	cross(t_vector u, t_vector v);
t_vector	normalize(t_vector v);
t_vector	vector_in_unit_sphere(void);
t_vector	vector_in_unit_disk(void);
t_vector	reflect(t_vector v, t_vector n);
t_vector	refract(t_vector uv, t_vector n, float eta_over_etaprime);
t_point		point_(float x, float y, float z);
t_color		color_(float r, float g, float b);
t_rotation	rotation_(float x, float y, float z);

#endif
