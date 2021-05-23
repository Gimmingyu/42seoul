/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:55:25 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 19:00:12 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#define RGB				3
#define FILEHEADER		14
#define DIBHEADER		40

void	put_byte(int file, t_byte byte, int count)
{
	while (count--)
		write(file, &byte, 1);
}

void	put_int(int file, int n)
{
	write(file, &n, 4);
}

void	file_header(int file, int pixel_count)
{
	int	size;
	int	data_offset;

	data_offset = FILEHEADER + DIBHEADER;
	size = data_offset + RGB * pixel_count;
	write(file, "BM", 2);
	put_int(file, size);
	put_byte(file, 0, 4);
	put_int(file, data_offset);
}

void	dib_header(int file, int width, int height, int pixel_count)
{
	put_int(file, DIBHEADER);
	put_int(file, width);
	put_int(file, height);
	put_byte(file, 1, 1);
	put_byte(file, 0, 1);
	put_byte(file, RGB * BYTE, 1);
	put_byte(file, 0, 1 + 4);
	put_int(file, pixel_count);
	put_int(file, 2835);
	put_int(file, 2835);
	put_byte(file, 0, 4 + 4);
}

void	pixel_array(int file, t_screen screen, int width, int height)
{
	int			x;
	int			y;
	const int	padding = width % 4;

	y = height;
	while (y--)
	{
		x = 0;
		while (x < width)
			write(file, &screen[x++][y], 3);
		put_byte(file, 0, padding);
	}
}
