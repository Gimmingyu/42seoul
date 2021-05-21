/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:10:39 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:10:40 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strdel_d(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
