/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:12:01 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/27 12:14:50 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int i;
	unsigned int cnt;

	i = 0 - 1;
	cnt = 0;
	while (dest[cnt])
		cnt++;
	while (src[++i])
		dest[cnt + i] = src[i];
	dest[cnt + i] = 0;
	return (dest);
}
