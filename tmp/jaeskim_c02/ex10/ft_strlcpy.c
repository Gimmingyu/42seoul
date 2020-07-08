/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 21:32:16 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/08 11:51:22 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int n;

	n = 0;
	while (*src && size > n + 1)
	{
		*dest++ = *src++;
		++n;
	}
	if (size >= n + 1)
		*dest = '\0';
	while (*src++)
		++n;
	return (n);
}
