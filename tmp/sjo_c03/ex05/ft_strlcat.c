/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 04:49:37 by sjo               #+#    #+#             */
/*   Updated: 2020/07/14 00:33:12 by sjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dsize;
	unsigned int ssize;

	dsize = 0;
	ssize = 0;
	while (dest[dsize])
		dsize++;
	while (src[ssize] && dsize + ssize + 1 < size)
	{
		dest[dsize + ssize] = src[ssize];
		ssize++;
	}
	dest[dsize + ssize] = 0;
	while (src[ssize])
		ssize++;
	if (size < dsize)
		return (ssize + size);
	else
		return (dsize + ssize);
}
