/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_para.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:04:04 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:04:08 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_read_ipara(t_form *form)
{
	long long int	i;

	if (form->hhll == 0)
		return ((long long int)va_arg(form->va_para, int));
	if (form->hhll == 1)
		return ((long long int)va_arg(form->va_para, long int));
	if (form->hhll == 2)
		return (va_arg(form->va_para, long long int));
	if (form->hhll == -1)
		i = (short int)va_arg(form->va_para, int);
	else
		i = (char)va_arg(form->va_para, int);
	return (i);
}

size_t			ft_read_upara(t_form *form)
{
	size_t	u;

	if (form->hhll == 0)
		return ((size_t)va_arg(form->va_para, unsigned int));
	if (form->hhll == 1)
		return ((size_t)va_arg(form->va_para, unsigned long int));
	if (form->hhll == 2)
		return (va_arg(form->va_para, unsigned long long int));
	if (form->hhll == -1)
		u = (unsigned short int)va_arg(form->va_para, unsigned int);
	else
		u = (unsigned char)va_arg(form->va_para, unsigned int);
	return (u);
}
