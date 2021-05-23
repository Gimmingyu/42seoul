/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:39:43 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/09 13:40:00 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_H
# define RANDOM_H

float		random_float(void);
float		random_float_(float min, float max);
t_vector	random_vector(void);
t_vector	random_vector_(float min, float max);
t_vector	random_in_unit_sphere(void);
t_vector	random_in_unit_disk(void);
t_vector	random_unit_vector(void);

#endif
