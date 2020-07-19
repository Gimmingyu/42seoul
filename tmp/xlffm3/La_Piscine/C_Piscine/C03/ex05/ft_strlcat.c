/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:29:43 by jipark            #+#    #+#             */
/*   Updated: 2020/01/26 16:44:58 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int count;
	unsigned int dest_length;
	unsigned int src_length;

	dest_length = 0;
	src_length = 0;
	while (dest[dest_length] != '\0')
		dest_length++;
	while (src[src_length] != '\0')
		src_length++;
	if (size >= dest_length + 2)
	{
		count = 0;
		while (count < size - dest_length - 1 && src[count] != '\0')
		{
			dest[dest_length + count] = src[count];
			count++;
		}
		dest[dest_length + count] = '\0';
	}
	if (size >= dest_length)
		return ((dest_length + src_length));
	else
		return ((src_length + size));
}
