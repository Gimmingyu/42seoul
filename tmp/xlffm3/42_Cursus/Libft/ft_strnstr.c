/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jipark <jipark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:37:41 by jipark            #+#    #+#             */
/*   Updated: 2020/04/06 14:56:22 by jipark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			i;
	size_t			i_tmp;
	unsigned int	j;
	unsigned int	little_len;

	if (!(*little))
		return ((char *)big);
	i = 0;
	little_len = ft_strlen(little);
	if (big == little)
		len = little_len;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		i_tmp = i;
		while (big[i_tmp] == little[j] && i_tmp < len)
		{
			i_tmp++;
			j++;
		}
		if (j == little_len)
			return ((char *)&(big[i]));
		i++;
	}
	return (0);
}
