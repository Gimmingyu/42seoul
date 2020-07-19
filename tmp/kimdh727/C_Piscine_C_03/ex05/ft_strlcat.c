/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:12:11 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/27 14:54:19 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int dest_size;
	unsigned int src_size;

	i = 0 - 1;
	dest_size = 0;
	src_size = 0;
	while (dest[dest_size])
		dest_size++;
	while (src[src_size])
		src_size++;
	if (!size)
		return (size + src_size);
	while (src[++i] && dest_size + i < size - 1)
		dest[dest_size + i] = src[i];
	dest[dest_size + i] = 0;
	if (dest_size > size)
		return (size + src_size);
	return (dest_size + src_size);
}
