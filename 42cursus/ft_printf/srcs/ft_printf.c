/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:03:27 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:03:28 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_form	form;

	va_start(form.va_para, format);
	form.result = 0;
	if (format)
		while (*format)
		{
			if (*format != '%')
			{
				write(1, format++, 1);
				++(form.result);
			}
			else
			{
				if (!(format + 1))
				{
					va_end(form.va_para);
					return (form.result);
				}
				form.result += ft_sub_printf(&format, &form);
			}
		}
	va_end(form.va_para);
	return (form.result);
}
