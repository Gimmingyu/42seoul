/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 19:53:00 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/08 14:31:02 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	i = 0;
	while (n && src[i])
	{
		dest[i] = src[i];
		++i;
		--n;
	}
	while ((unsigned int)i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}
