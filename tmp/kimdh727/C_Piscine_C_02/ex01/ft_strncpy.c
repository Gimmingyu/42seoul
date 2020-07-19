/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:11:32 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/25 19:32:39 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0 - 1;
	while (++i < n && src[i] != 0)
		dest[i] = src[i];
	i--;
	while (++i < n)
		dest[i] = 0;
	return (dest);
}
