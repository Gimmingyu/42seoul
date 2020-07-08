/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:29:59 by gim               #+#    #+#             */
/*   Updated: 2020/07/08 17:13:01 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned int	fin;

	i = 0;
	fin = 0;
	while (i < n)
	{
		if (fin == 1 || src[i] == '\0')
		{
			dest[i] = '\0';
			fin = 1;
		}
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
