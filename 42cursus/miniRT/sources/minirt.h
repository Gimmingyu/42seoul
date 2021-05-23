/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 11:40:34 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:57:30 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "etc/typedef.h"
# include "input/input.h"

int				clamp(int n, int min, int max);
void			refresh(t_scene *scene);
int				loop_(void);
void			loop(void);
void			init_(void);
void			init(void);
void			clear(void);
void			put(int x, int y, int color);
int				quit(int status, char *error);
void			window(int width, int height, char *title);
void			check_closed(void);
int				hexcolor(t_pixel rgb);
void			save(t_screen screen);
t_pixel			rgbcolor(int hex);
t_byte			byte_(int n);
void			save(t_screen screen);
t_bool			hit_sphere(t_sphere *s, t_ray *r, t_range range, t_hit *hit);
void			set_face_normal(t_hit *contact, t_ray *ray, t_vector outward);
t_ray			ray_(t_point origin, t_vector direction);
t_point			at(t_ray *r, float scalar);
float			degrees_to_radians(float degrees);
float			radians_to_degrees(float radians);
float			clamp_float(float x, float min, float max);
float			solve(float a, float half_b, float c, t_range range);
t_camera		camera_(t_setup i);
t_ray			get_ray(t_camera *c, int x, int y);

t_material		lambertian_(t_color color);
t_material		metal_(t_color color, float fuzz);
t_material		dielectric_(t_color color, float ir);
t_material		emissive_(t_color rgb);

t_color			point_light(t_hit *contact);
void			push(t_object **object, t_object *new);
void			join(t_object **object, t_object *new, int count);

t_circle		circle__(t_point center, float radius);
t_object		*circle_(t_point center, float radius, t_rotation angle,
					t_material material);
t_object		*sphere_(t_point center, float radius, t_material material);
t_object		*rectangle_(t_point center, t_vector size, t_rotation angle,
					t_material material);
t_object		*box_(t_point center, t_vector size, t_rotation angle,
					t_material material);
t_object		*pyramid_(t_point center, t_vector size, t_rotation angle,
					t_material material);
t_object		*triangle_(t_point p0, t_point p1, t_point p2,
					t_material material);
t_object		*cylinder_(t_circle end, float height, t_rotation angle,
					t_material material);
t_object		*plane_(t_point center, t_vector normal, t_material material);
t_object		*spot_(t_light light);
t_object		*object_(t_hittable object);

t_bool			hit(t_object *current, t_ray *r, t_range range, t_hit *contact);
t_bool			hit_plane(t_plane *p, t_ray *r, t_range range, t_hit *contact);
t_bool			hit_box(t_box *b, t_ray *r, t_range range, t_hit *contact);
t_bool			hit_spot(t_spot *s, t_ray *r, t_range range, t_hit *contact);
t_bool			hit_cylinder(t_cylinder *cy, t_ray *r, t_range range,
					t_hit *contact);
t_bool			hit_triangle(t_riangle *t, t_ray *r, t_range range,
					t_hit *contact);
t_bool			hit_rectangle(t_rectangle *rect, t_ray *r, t_range range,
					t_hit *contact);
t_bool			hit_circle(t_circle *c, t_ray *r, t_range range,
					t_hit *contact);
void			hit_spots(t_object *current, t_ray *r, t_range range,
					t_hit *contact);

t_range			range_(float min, float max);
t_bool			is_in(float n, t_range range);

t_raw			raw_(int width, int height);
void			free_raw(t_raw raw, int width);
void			reset(t_raw raw, int width, int height);

t_screen		screen_(int width, int height);
void			free_screen(t_screen screen, int width);
void			show(t_screen screen, int width, int height);

t_vector		rotate(t_vector v_, t_rotation angle);
t_material		material_(t_surface s, t_color c, float f, float ir);

t_bool			scatter(t_ray *in, t_hit *contact,
					t_color *attenuation, t_ray *out);
t_bool			metal_scatter(t_ray *in, t_hit *contact,
					t_color *attenuation, t_ray *out);
t_bool			lambertian_scatter(t_hit *contact,
					t_color *attenuation, t_ray *out);
t_bool			dielectric_scatter(t_ray *in, t_hit *contact,
					t_color *attenuation, t_ray *out);
t_vector		rotate(t_vector v_, t_rotation angle);
void			get_screen_size(int *width, int *height);
t_vector		get_angle(t_vector v);

int				get_int(t_bool is_signed, char **c);
float			get_float(char **c);
t_color			get_color(char **c);
t_point			get_coordinate(char **c);
t_vector		get_orientation(char **c);
void			check_spaces(char **c);
int				get_next_line(int file, char **line);
t_bool			is_(char **a, char *b);
t_bool			add_sphere(t_scene *scene, char **c);
t_bool			add_plane(t_scene *scene, char **c);
t_bool			add_square(t_scene *scene, char **c);
t_bool			add_cylinder(t_scene *scene, char **c);
t_bool			add_triangle(t_scene *scene, char **c);
void			read_file(char *path);

void			record(void);
void			record_samples(int x, int y);
void			record_(t_screen screen, t_raw pixels, int samples);

t_color			color_ray(t_ray *r, t_scene *s, t_object *world, int depth);
t_scene			*scene_(void);

t_bool			add_light(t_scene *scene, char **c);
t_bool			add_camera(t_scene *scene, char **c);

t_bool			set_resolution(t_scene *scene, char **c);
t_bool			set_ambient(t_scene *scene, char **c);

t_bool			is_digit(char c);
t_bool			is(char **a, char b);
t_bool			is_(char **a, char *b);
t_bool			is_among(char **c, char *string);

void			check(char **a, char b);
void			check_spaces(char **c);

int				get_number(char **c);
float			get_fraction(char **c);
int				get_int(t_bool is_signed, char **c);
float			get_float(char **c);

t_color			get_color(char **c);
t_point			get_coordinate(char **c);
t_vector		get_orientation(char **c);

t_bool			has_value(t_vector *v);
t_vector		get(float (*f)(float), t_vector *u);

t_bool			handle_line(t_scene *scene, char *line);
t_material		get_material(t_color color, char **c);
t_bool			add_box(t_scene *scene, char **c);
t_bool			add_pyramid(t_scene *scene, char **c);

void			put_byte(int file, t_byte byte, int count);
void			put_int(int file, int n);
void			file_header(int file, int pixel_count);
void			dib_header(int file, int width, int height, int pixel_count);
void			pixel_array(int file, t_screen screen, int width, int height);

#endif
