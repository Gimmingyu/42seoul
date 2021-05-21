/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:56:39 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:56:40 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

char	*ft_get_fd(int fd)
{
	char	*line;
	int		res;

	while ((res = get_next_line(fd, &line)) > 0)
		return (line);
	return (NULL);
}
