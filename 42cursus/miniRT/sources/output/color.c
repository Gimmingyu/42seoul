/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:27:17 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/11 18:28:56 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

#define BLACK	0x000000
#define RED		0xFF0000
#define GREEEN	0x00FF00
#define BLUE	0x0000FF

t_pixel	rgbcolor(int hex)
{
	t_pixel	*color;

	color = (t_pixel *)&hex;
	return (*color);
}

int		hexcolor(t_pixel rgb)
{
	int		*color;

	color = (int*)&rgb;
	return (BLACK | *color);
}
