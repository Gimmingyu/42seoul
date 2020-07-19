/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:12:05 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/27 16:02:22 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int cnt;

	i = 0 - 1;
	cnt = 0;
	while (dest[cnt])
		cnt++;
	while (src[++i] && i < nb)
		dest[cnt + i] = src[i];
	dest[cnt + i] = 0;
	return (dest);
}
