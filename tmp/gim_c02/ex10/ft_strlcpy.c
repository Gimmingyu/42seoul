/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gim <gim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 20:46:59 by gim               #+#    #+#             */
/*   Updated: 2020/07/08 17:03:16 by gim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	if (size > 0)
	{
		while (i < size - 1)
		{
			if (src[i] == '\0')
			{
				dest[i] = '\0';
				break ;
			}
			dest[i] = src[i];
			i++;
		}
		dest[size - 1] = '\0';
	}
	while (*src != '\0')
	{
		len++;
		src++;
	}
	return (len);
}
