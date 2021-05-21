/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:02:58 by kyekim            #+#    #+#             */
/*   Updated: 2021/05/12 15:02:59 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_parse_width(const char *str, t_arg *arg)
{
	int i;

	i = 0;
	if (*str == '*')
	{
		arg->min_width = -1;
		while (*(str + i) == '*')
			i++;
	}
	else if (*(str + i) >= '0' && *(str + i) <= '9')
	{
		arg->min_width = ft_atoi(str + i);
		while (*(str + i) >= '0' && *(str + i) <= '9')
			i++;
	}
	return (i);
}
