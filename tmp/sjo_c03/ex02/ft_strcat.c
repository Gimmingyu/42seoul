/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjo <twwj4134@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 20:24:19 by sjo               #+#    #+#             */
/*   Updated: 2020/07/09 10:37:31 by sjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int check;
	int up;

	up = 0;
	check = 0;
	while (dest[check] != '\0')
	{
		check++;
	}
	while (src[up] != '\0')
	{
		dest[check] = src[up];
		check++;
		up++;
	}
	dest[check] = '\0';
	return (dest);
}
