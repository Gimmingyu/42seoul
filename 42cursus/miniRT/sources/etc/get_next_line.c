/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:00:26 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/23 18:28:13 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

static char	*duplicate(char *s, int length, int result)
{
	char	*copy;

	if (result == ERROR)
		return (NULL);
	copy = malloc(++length);
	if (copy)
		while (length--)
			copy[length] = s[length];
	else
		result = ERROR;
	return (copy);
}

int			get_next_line(int file, char **line)
{
	int		result;
	int		i;
	char	c;
	char	temp[MAX + 1];

	i = 0;
	*temp = 0;
	result = read(file, &c, 1);
	while (result)
	{
		if (c == '\n')
			break ;
		if (result == ERROR)
			quit(READ, "get_next_line()");
		if (i == MAX)
			quit(MISCONFIG, "get_next_line()");
		temp[i] = c;
		temp[++i] = 0;
		result = read(file, &c, 1);
	}
	*line = duplicate(temp, i, result);
	return (result);
}
