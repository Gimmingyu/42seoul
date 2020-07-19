/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:35:52 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/31 00:41:23 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*duplicate;

	len = 0;
	while (src[len])
		len++;
	duplicate = (char *)malloc(sizeof(char) * ++len);
	while (len--)
		duplicate[len] = src[len];
	return (duplicate);
}
