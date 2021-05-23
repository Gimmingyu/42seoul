/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:36:11 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:45:09 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H

# include "define.h"

typedef unsigned char	t_byte;

typedef struct			s_pixel
{
	t_byte	b;
	t_byte	g;
	t_byte	r;
}						t_pixel;

typedef enum			e_bool
{
	false,
	true
}						t_bool;

typedef struct			s_point
{
	float	x;
	float	y;
	float	z;
}						t_point;

typedef t_point			t_vector;
typedef t_point			t_rotation;
typedef t_point			t_color;
typedef t_pixel			**t_screen;
typedef t_color			**t_raw;

typedef struct			s_light
{
	t_point	center;
	t_color	color;
	float	brightness;
}						t_light;

typedef struct			s_phere
{
	t_point	center;
	float	radius;
}						t_sphere;

typedef enum			e_geometry
{
	_sphere,
	_xy,
	_yz,
	_xz,
	_box,
	_cylinder,
	_triangle,
	_plane,
	_circle,
	_spot,
	_rectangle
}						t_geometry;

typedef enum			e_surface
{
	plain,
	metal,
	lambertian,
	dielectric,
	emissive
}						t_surface;

typedef struct			s_material
{
	t_surface	surface;
	float		fuzz;
	float		ir;
	t_color		albedo;
	t_color		emittor;
}						t_material;

typedef struct			s_hit
{
	t_material	material;
	t_point		point;
	t_vector	normal;
	float		distance;
	t_bool		front_face;
}						t_hit;

typedef struct			s_hittable
{
	t_geometry	geometry;
	t_material	material;
	void		*pointer;
}						t_hittable;

typedef struct			s_range
{
	float	min;
	float	max;
}						t_range;

typedef struct			s_ray
{
	t_point		origin;
	t_vector	direction;
}						t_ray;

typedef struct			s_object
{
	t_hittable			object;
	struct s_object		*next;
}						t_object;

typedef struct			s_camera
{
	t_point		origin;
	t_point		lower_left;
	t_vector	horizontal;
	t_vector	vertical;
	t_vector	front;
	t_vector	right;
	t_vector	up;
	float		lens_radius;
}						t_camera;

typedef struct			s_etup
{
	t_light		light;
	t_point		origin;
	t_point		target;
	t_vector	up;
	float		fov;
	float		aspect_ratio;
	float		aperture;
	float		focus;
}						t_setup;

typedef struct			s_rectangle
{
	t_point	p[4];
}						t_rectangle;

typedef struct			s_box
{
	t_rectangle	side[6];
}						t_box;

typedef struct			s_circle
{
	t_point		center;
	t_vector	normal;
	float		radius;
}						t_circle;

typedef struct			s_cylinder
{
	t_circle	end[2];
	float		height;
}						t_cylinder;

typedef struct			s_triangle
{
	t_point	p[3];
}						t_riangle;

typedef struct			s_pot
{
	t_light	light;
}						t_spot;

typedef struct			s_plane
{
	t_vector	normal;
	float		distance;
}						t_plane;

typedef struct			s_quaternion
{
	t_vector	v;
	float		w;
}						t_quaternion;

typedef struct			s_cene
{
	t_setup		setup[MAX];
	t_camera	camera[MAX];
	t_color		ambient_light;
	t_color		filter;
	t_color		background;
	t_object	*world;
	t_raw		raw;
	t_screen	screen;
	void		*graphics;
	void		*window;
	int			width;
	int			height;
	int			accumulated;
	int			samples_limit;
	int			depth_limit;
	int			samples;
	int			depth;
	t_bool		is_saving;
	short		camera_count;
	short		current;
}						t_scene;

#endif
