/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allflag_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 11:59:41 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 11:59:46 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_size_check(const char **format, t_form *form)
{
	char	hhll;

	hhll = 0;
	if (**format == 'l')
	{
		++hhll;
		++(*format);
		if (**format == 'l')
		{
			++hhll;
			++(*format);
		}
	}
	else if (**format == 'h')
	{
		--hhll;
		++(*format);
		if (**format == 'h')
		{
			--hhll;
			++(*format);
		}
	}
	form->hhll = hhll;
}

void	ft_precision_check(const char **format, t_form *form)
{
	int		precision;

	if (**format != '.')
	{
		form->precision = -1;
		return ;
	}
	++(*format);
	if (**format == '*')
	{
		++(*format);
		precision = va_arg(form->va_para, int);
	}
	else
	{
		precision = 0;
		while (ft_isdigit(**format))
			precision = precision * 10 + (int)(*((*format)++) - '0');
	}
	form->precision = precision;
}

void	ft_width_check(const char **format, t_form *form)
{
	int		width;

	if (**format == '*')
	{
		++(*format);
		width = va_arg(form->va_para, int);
		if (width < 0)
		{
			width *= -1;
			form->ladjust = '-';
		}
	}
	else
	{
		width = 0;
		while (ft_isdigit(**format))
			width = width * 10 + (int)(*((*format)++) - '0');
	}
	form->width = width;
}

void	ft_flag_check(const char **format, t_form *form)
{
	form->ladjust = 0;
	form->padc = " ";
	form->sign = 0;
	form->hash_flag = 0;
	while (**format == '-' || **format == '0' || **format == '+'
		|| **format == ' ' || **format == '#')
	{
		if (**format == '-')
			form->ladjust = '-';
		else if (**format == '0')
			form->padc = "0";
		else if (**format == '+')
			form->sign = '+';
		else if (!form->sign && **format == ' ')
			form->sign = ' ';
		else if (**format == '#')
			form->hash_flag = '#';
		++(*format);
	}
}
