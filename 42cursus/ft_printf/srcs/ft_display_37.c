/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_37.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:59:54 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:59:56 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_37(t_form *form)
{
	int		result;

	result = 0;
	if (!form->ladjust)
		while (--(form->width) > 0)
			result += (int)write(1, form->padc, 1);
	result += (int)write(1, "%", 1);
	while (--(form->width) > 0)
		result += (int)write(1, " ", 1);
	return (result);
}
