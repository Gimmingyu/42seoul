/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:24:53 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 19:12:53 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				check;

	i = 0;
	check = 0;
	while (i < n)
	{
		if (check == 1 || src[i] == '\0')
		{
			dest[i] = '\0';
			check = 1;
		}
		else
			dest[i] = src[i];
		i++;
	}
	return (dest);
}
