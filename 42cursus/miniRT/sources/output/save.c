/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:20:15 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:57:59 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#define RGB			3
#define FILEHEADER	14
#define DIBHEADER	40

void	save(t_screen screen)
{
	const char	*filename = "img.bmp";
	const int	width = scene_()->width;
	const int	height = scene_()->height;
	const int	pixel_count = (width + width % 4) * height;
	int			file;

	file = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file == ERROR)
		quit(OPEN, "save()");
	file_header(file, pixel_count);
	dib_header(file, width, height, pixel_count);
	pixel_array(file, screen, width, height);
}
