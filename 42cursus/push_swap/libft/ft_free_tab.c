/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:56:29 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:56:31 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_free_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(*str);
	str = NULL;
}
