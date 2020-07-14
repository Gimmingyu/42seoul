/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjo <twwj4134@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:41:55 by sjo               #+#    #+#             */
/*   Updated: 2020/07/09 10:38:02 by sjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char			*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int check;
	unsigned int up;

	up = 0;
	check = 0;
	while (dest[check] != '\0')
	{
		check++;
	}
	while (up < nb && src[up] != '\0')
	{
		dest[check] = src[up];
		check++;
		up++;
	}
	if (dest[check] != '\0')
		dest[check] = '\0';
	return (dest);
}
