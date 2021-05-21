/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_88xpo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:00:21 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:00:25 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_display_x(t_form *form)
{
	size_t	x;
	int		result;

	x = ft_read_upara(form);
	form->pre_width = (form->hash_flag && x) ? 2 : 0;
	form->put_width = (form->precision || x) ? ft_uilen(x, 16) : 0;
	if (form->precision > (int)form->put_width)
		form->put_width = form->precision;
	form->width -= form->put_width + form->pre_width;
	result = 0;
	if (!(*form->padc == '0' && form->precision < 0) && !form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, " ", 1);
	if (form->pre_width)
		result += (int)write(1, (form->specifier == 'x' ? "0x" : "0X"), 2);
	if (form->put_width)
	{
		if (form->specifier == 'x')
			result += ft_putnbr_mk2(x, HEXLOW, 16, form);
		else
			result += ft_putnbr_mk2(x, HEXUP, 16, form);
	}
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}

int		ft_display_p(t_form *form)
{
	size_t	p;
	int		result;

	p = (size_t)va_arg(form->va_para, void *);
	form->put_width = (form->precision || p) ? ft_uilen(p, 16) : 0;
	if (form->precision > (int)form->put_width)
		form->put_width = form->precision;
	form->width -= form->put_width + 2;
	result = 2;
	if (!(*form->padc == '0' && form->precision < 0) && !form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, " ", 1);
	write(1, "0x", 2);
	if (form->put_width)
		result += ft_putnbr_mk2(p, HEXLOW, 16, form);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}

int		ft_display_o(t_form *form)
{
	size_t	o;
	int		result;

	o = ft_read_upara(form);
	form->pre_width = 0;
	form->put_width = (form->precision || o) ? ft_uilen(o, 8) : 0;
	if (form->precision > (int)form->put_width)
	{
		form->hash_flag = 0;
		form->pre_width = (size_t)(form->precision) - form->put_width;
	}
	if (form->hash_flag && !(form->pre_width) && (!(form->put_width) || o))
		++(form->pre_width);
	form->put_width += form->pre_width;
	form->width -= form->put_width;
	result = 0;
	if (!(*form->padc == '0' && form->precision < 0) && !form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, " ", 1);
	if (form->put_width)
		result += ft_putnbr_mk2(o, OCTAL, 8, form);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}
