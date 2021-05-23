/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:36:28 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:46:36 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include "../math/vector.h"

t_bool	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

t_bool	is(char **a, char b)
{
	if (**a == b)
	{
		(*a)++;
		return (true);
	}
	return (false);
}

t_bool	is_(char **a, char *b)
{
	int		i;

	i = 0;
	while ((*a)[i] && b[i] && (*a)[i] == b[i])
		i++;
	if (!b[i])
	{
		*a += i;
		return (true);
	}
	return (false);
}

t_bool	is_among(char **c, char *string)
{
	int		i;

	i = 0;
	while (string[i] && **c != string[i])
		i++;
	return (is(c, string[i]));
}
