/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 09:37:04 by jipark            #+#    #+#             */
/*   Updated: 2020/01/26 15:11:15 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int index;
	int count;

	count = 0;
	index = 0;
	while (dest[index] != '\0')
		index++;
	while (src[count] != '\0')
	{
		dest[index] = src[count];
		index++;
		count++;
	}
	dest[index] = '\0';
	return (dest);
}
