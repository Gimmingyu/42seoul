/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_mk2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:03:41 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:03:43 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_sub_putnbr_mk2(size_t ui, int base, char *put)
{
	if (ui >= (size_t)base)
		ft_sub_putnbr_mk2(ui / (size_t)base, base, put);
	write(1, &put[ui % base], 1);
}

int		ft_uilen(size_t ui, int base)
{
	int	result;

	result = 1;
	while (ui >= (size_t)base)
	{
		++result;
		ui = ui / (size_t)base;
	}
	return (result);
}

int		ft_putnbr_mk2(size_t ui, char *put, int base, t_form *form)
{
	int	result;
	int	i;

	result = 0;
	i = ft_uilen(ui, base);
	if (form->width > 0 && !form->ladjust)
		while (form->width--)
			result += (int)write(1, put, 1);
	if ((int)form->put_width > i)
		while ((int)form->put_width != i)
			i += (int)write(1, put, 1);
	ft_sub_putnbr_mk2(ui, base, put);
	return (result + i);
}
