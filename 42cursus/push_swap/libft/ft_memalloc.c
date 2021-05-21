/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:00:58 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:00:59 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mem;

	if (!(mem = malloc(sizeof(char) * size)))
		return (NULL);
	if (mem)
	{
		ft_bzero(mem, size);
		return (mem);
	}
	return (NULL);
}
