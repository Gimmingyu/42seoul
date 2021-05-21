/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:04:32 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:04:34 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifier(t_form *form)
{
	if (form->specifier == 'c')
		return (ft_display_c(form));
	if (form->specifier == 's')
		return (ft_display_s(form));
	if (form->specifier == 'p')
		return (ft_display_p(form));
	if (form->specifier == 'd' || form->specifier == 'i')
		return (ft_display_d(form));
	if (form->specifier == 'u')
		return (ft_display_u(form));
	if (form->specifier == 'x' || form->specifier == 'X')
		return (ft_display_x(form));
	if (form->specifier == 'o')
		return (ft_display_o(form));
	if (form->specifier == '%')
		return (ft_display_37(form));
	if (form->specifier == 'f')
		return (ft_display_f(form, va_arg(form->va_para, double)));
	if (form->specifier == 'e')
		return (ft_display_e(form, va_arg(form->va_para, double)));
	if (form->specifier == 'g')
		return (ft_display_g(form, va_arg(form->va_para, double)));
	if (form->specifier == 'n')
		return (ft_handle_n(form));
	return (ft_display_all(form));
}

int	ft_sub_printf(const char **format, t_form *form)
{
	int		result;

	++(*format);
	ft_flag_check(format, form);
	ft_width_check(format, form);
	ft_precision_check(format, form);
	ft_size_check(format, form);
	form->specifier = **format;
	result = ft_check_specifier(form);
	if (**format)
		++(*format);
	return (result);
}
