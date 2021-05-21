/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:11:07 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:11:08 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strisalpha(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	else
	{
		i = 0;
		while (str[i])
		{
			if (ft_isalpha(str[i]))
				i++;
			else
				return (0);
		}
	}
	return (1);
}
