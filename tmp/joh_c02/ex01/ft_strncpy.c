/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 11:21:08 by joh               #+#    #+#             */
/*   Updated: 2020/07/08 17:27:33 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int index;

	index = 0;
	while (index < (int)n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < (int)n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}
