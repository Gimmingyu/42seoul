/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:56:02 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 14:56:03 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_free_arg(char **tab_mant, char *str)
{
	int i;

	i = 0;
	while (tab_mant[i])
	{
		ft_strdel(&tab_mant[i]);
		i++;
	}
	free(tab_mant);
	ft_strdel(&str);
}
