/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:25:56 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:00:47 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_screen	screen_(int width, int height)
{
	t_screen	screen;

	screen = malloc(sizeof(t_color *) * width);
	if (!screen)
		quit(MALLOC, "screen_()");
	while (width--)
	{
		screen[width] = malloc(sizeof(t_color) * height);
		if (!screen[width])
			quit(MALLOC, "screen_()");
	}
	return (screen);
}

void		free_screen(t_screen screen, int width)
{
	while (width--)
		free(screen[width]);
	free(screen);
}

void		show(t_screen screen, int width, int height)
{
	int	x;
	int	y;

	x = width;
	while (x--)
	{
		y = height;
		while (y--)
			put(x, y, hexcolor(screen[x][y]));
	}
}
