/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:29:09 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/11 19:19:16 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

void	reset(t_raw raw, int width, int height)
{
	int	x;
	int	y;

	x = width;
	while (x--)
	{
		y = height;
		while (y--)
			update(&raw[x][y], 0, 0, 0);
	}
}

t_raw	raw_(int width, int height)
{
	t_raw	raw;
	int		x;

	raw = malloc(sizeof(t_color *) * width);
	if (!raw)
		quit(MALLOC, "raw()");
	x = width;
	while (x--)
	{
		raw[x] = malloc(sizeof(t_color) * height);
		if (!raw[x])
			quit(MALLOC, "raw()");
	}
	reset(raw, width, height);
	return (raw);
}

void	free_raw(t_raw raw, int width)
{
	while (width--)
		free(raw[width]);
	free(raw);
}
