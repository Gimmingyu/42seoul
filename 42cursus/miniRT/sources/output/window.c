/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:29:20 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/11 19:33:02 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	window(int width, int height, char *title)
{
	t_scene	*scene;

	scene = scene_();
	scene->graphics = mlx_init();
	scene->window = mlx_new_window(scene->graphics, width, height, title);
}

char	*which(int error)
{
	if (error == MALLOC)
		return ("MALLOC");
	if (error == MISCONFIG)
		return ("MISCONFIG");
	if (error == OPEN)
		return ("OPEN");
	if (error == THREAD_ERROR)
		return ("THREAD_ERROR");
	return ("OTHER");
}

int		quit(int status, char *error)
{
	if (status)
		printf("Error\n%s: %s\n", which(status), error);
	exit(0);
	return (status);
}

void	check_closed(void)
{
	mlx_hook(scene_()->window, CLOSED, 0, &quit, NULL);
}
