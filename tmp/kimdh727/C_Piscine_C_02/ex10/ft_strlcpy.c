/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwki <donghwki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:12:18 by donghwki          #+#    #+#             */
/*   Updated: 2020/01/25 21:40:26 by donghwki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	unsigned int cnt;

	cnt = 0;
	while (src[cnt] != 0)
		cnt++;
	if (!n)
		return (cnt);
	i = 0;
	while (src[i] != 0 && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (cnt);
}
