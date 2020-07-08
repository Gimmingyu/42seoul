/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joh <joh@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 15:00:13 by joh               #+#    #+#             */
/*   Updated: 2020/07/06 15:04:40 by joh              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
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
		if (cmp >= 'a' && cmp <= 'z')
		{
			str[index] = cmp - 32;
		}
		index++;
	}
	return (str);
}
