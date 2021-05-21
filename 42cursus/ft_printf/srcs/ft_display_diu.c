/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_diu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:01:00 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:01:01 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_d(t_form *form)
{
	long long int	d;
	int				result;

	d = ft_read_ipara(form);
	if (d < 0)
	{
		form->sign = '-';
		d *= -1;
	}
	form->put_width = (form->precision || d) ? ft_uilen((size_t)d, 10) : 0;
	if (form->precision > (int)form->put_width)
		form->put_width = form->precision;
	form->width -= form->put_width + (form->sign ? 1 : 0);
	result = 0;
	if (!(*form->padc == '0' && form->precision < 0) && !form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, " ", 1);
	if (form->sign)
		result += (int)write(1, &form->sign, 1);
	if (form->put_width)
		result += ft_putnbr_mk2((size_t)d, DIGIT, 10, form);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}

int		ft_display_u(t_form *form)
{
	size_t			u;
	int				result;

	u = ft_read_upara(form);
	form->put_width = (form->precision || u) ? ft_uilen(u, 10) : 0;
	if (form->precision > (int)form->put_width)
		form->put_width = form->precision;
	form->width -= form->put_width;
	result = 0;
	if (!(*form->padc == '0' && form->precision < 0) && !form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, " ", 1);
	if (form->put_width)
		result += ft_putnbr_mk2((size_t)u, DIGIT, 10, form);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}
