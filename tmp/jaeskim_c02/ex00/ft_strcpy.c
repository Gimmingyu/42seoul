/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 10:00:43 by jaeskim           #+#    #+#             */
/*   Updated: 2020/07/08 14:30:18 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char *cp;

	cp = dest;
	while ((*cp++ = *src++))
		;
	*cp = '\0';
	return (dest);
}