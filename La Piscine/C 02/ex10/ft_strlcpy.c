/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 12:12:33 by kyekim            #+#    #+#             */
/*   Updated: 2020/07/13 12:12:35 by kyekim           ###   ########.fr       */
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
