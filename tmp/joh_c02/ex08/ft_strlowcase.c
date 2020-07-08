/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:06:13 by joh               #+#    #+#             */
/*   Updated: 2020/07/06 15:11:32 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int		index;
	char	cmp;

	index = 0;
	while (1)
	{
		cmp = str[index];
		if (cmp == '\0')
		{
			break ;
		}
		if (cmp >= 'A' && cmp <= 'Z')
		{
			str[index] = cmp + 32;
		}
		index++;
	}
	return (str);
}
