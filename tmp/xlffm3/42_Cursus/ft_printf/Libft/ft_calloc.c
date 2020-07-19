/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:04:30 by jipark            #+#    #+#             */
/*   Updated: 2020/02/26 18:04:30 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tmp;
	size_t	total_size;

	total_size = nmemb * size;
	if (!(tmp = (void *)malloc(total_size)))
		return (0);
	ft_memset(tmp, 0, total_size);
	return (tmp);
}
