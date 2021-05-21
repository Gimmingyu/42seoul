/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:02:20 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:02:24 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_null(t_form *form)
{
	int		result;

	result = 0;
	if (form->precision > 6)
		form->precision = 6;
	form->width -= form->precision;
	if (!form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, form->padc, 1);
	result += (int)write(1, "(null)", form->precision);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}

int	ft_wchar_len(wchar_t wc)
{
	if (wc < 0x0080)
		return (1);
	if (wc < 0x0800)
		return (2);
	if (wc < 0x10000)
		return (3);
	return (4);
}

int	ft_display_ws(t_form *form, wchar_t *ws)
{
	int	result;
	int	i;
	int	tmp;

	if (!ws)
		return (ft_display_null(form));
	i = -1;
	form->put_width = 0;
	while (ws[++i])
	{
		tmp = ft_wchar_len(ws[i]);
		if (form->put_width + (size_t)tmp > (size_t)form->precision)
			break ;
		form->put_width += (size_t)tmp;
	}
	form->width -= form->put_width;
	result = form->put_width;
	if (!form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, " ", 1);
	while (i--)
		ft_display_wc((wint_t)(*(ws++)));
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}

int	ft_display_s(t_form *form)
{
	char	*s;
	int		result;

	if (form->precision < 0)
		form->precision = 0x7FFFFFFF;
	if (form->hhll == 1)
		return (ft_display_ws(form, va_arg(form->va_para, wchar_t *)));
	s = va_arg(form->va_para, char *);
	if (!s)
		return (ft_display_null(form));
	form->put_width = (int)ft_strlen(s);
	result = 0;
	if ((size_t)form->precision < form->put_width)
		form->put_width = (size_t)form->precision;
	form->width -= form->put_width;
	if (!form->ladjust)
		while (form->width-- > 0)
			result += (int)write(1, form->padc, 1);
	result += (int)write(1, s, form->put_width);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}
