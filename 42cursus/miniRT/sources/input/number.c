/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:38:15 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:53:44 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

int		get_number(char **c)
{
	int	n;

	n = 0;
	while (is_digit(**c))
	{
		n *= 10;
		n += **c - '0';
		(*c)++;
		if (n < 0)
			quit(MISCONFIG, "get_number()");
	}
	return (n);
}

float	get_fraction(char **c)
{
	float	n;
	float	digit;

	n = 0;
	digit = 1;
	while (is_digit(**c))
	{
		digit /= 10;
		n += (**c - '0') * digit;
		(*c)++;
	}
	return (n);
}

int		get_int(t_bool is_signed, char **c)
{
	long	n;

	n = 1;
	if (is_signed)
		if (is(c, '-'))
			n = -1;
	if (!is_digit(**c))
		quit(MISCONFIG, "get_int()");
	n *= get_number(c);
	return (n);
}

float	get_float(char **c)
{
	float	integer;
	float	fraction;
	t_bool	is_negative;

	fraction = 0;
	is_negative = **c == '-';
	integer = get_int(SIGNED, c);
	if (is(c, '.'))
		fraction = get_fraction(c);
	if (is_negative)
		fraction *= -1;
	return (integer + fraction);
}
