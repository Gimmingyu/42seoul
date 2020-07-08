/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 20:01:46 by joh               #+#    #+#             */
/*   Updated: 2020/07/08 15:43:06 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	len;

	len = 0;
	index = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	if (size != 0)
	{
		while (src[index] != '\0' && index < (size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (len);
}
