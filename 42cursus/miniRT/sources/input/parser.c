/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:38:29 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:49:40 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

#ifndef BONUS

t_bool		handle_line(t_scene *scene, char *line)
{
	if (!(set_resolution(scene, &line)
			|| set_ambient(scene, &line)
			|| add_camera(scene, &line)
			|| add_light(scene, &line)
			|| add_sphere(scene, &line)
			|| add_plane(scene, &line)
			|| add_square(scene, &line)
			|| add_cylinder(scene, &line)
			|| add_triangle(scene, &line)) || *line)
		return (false);
	else
		return (true);
}

t_material	get_material(t_color color, char **c)
{
	(void)c;
	return (lambertian_(color));
}

#endif

void		check(char **a, char b)
{
	if (!is(a, b))
		quit(MISCONFIG, "check()");
}

void		check_spaces(char **c)
{
	if (!is_among(c, " \r\f\t\v"))
		quit(MISCONFIG, "check_spaces()");
	while (is_among(c, " \r\f\t\v"))
		;
}

void		read_file(char *path)
{
	t_scene	*scene;
	char	*line;
	int		file;
	int		has_more;

	scene = scene_();
	file = open(path, O_RDONLY);
	has_more = get_next_line(file, &line);
	while (has_more != ERROR)
	{
		if (*line && !handle_line(scene, line))
			quit(MISCONFIG, "read_file()");
		free(line);
		if (!has_more)
			break ;
		has_more = get_next_line(file, &line);
	}
	if (has_more == ERROR || scene->camera_count <= 0)
		quit(MISCONFIG, "read_file()");
}
