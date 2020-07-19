/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 21:56:08 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 22:05:51 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int index;
	int src_index;

	index = 0;
	while (dest[index] != '\0')
		index++;
	src_index = 0;
	while (src[src_index] != '\0')
	{
		dest[index + src_index] = src[src_index];
		src_index++;
	}
	dest[index + src_index] = '\0';
	return (dest);
}
