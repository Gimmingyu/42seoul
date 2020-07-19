/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 12:57:46 by jipark            #+#    #+#             */
/*   Updated: 2020/01/26 15:12:59 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int count;
	unsigned int index;

	count = 0;
	index = 0;
	if (nb != 0)
	{
		while (dest[index] != '\0')
			index++;
		while (count < nb && src[count] != '\0')
		{
			dest[index] = src[count];
			index++;
			count++;
		}
		dest[index] = '\0';
	}
	return (dest);
}
