/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:00:50 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:00:52 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_wc(wint_t wc)
{
	unsigned int	put[4];
	int				len;

	if (wc < 0x0080)
		return ((int)write(1, &wc, 1));
	if (wc < 0x10000)
	{
		len = 3;
		put[0] = (wc >> 12) + 0xE0;
		put[1] = ((wc >> 6) & 0x3F) + 0x80;
		put[2] = (wc & 0x3F) + 0x80;
		if (wc < 0x0800)
		{
			len = 2;
			put[0] = (wc >> 6) + 0xC0;
			put[1] = (wc & 0x3F) + 0x80;
		}
		return ((int)write(1, put, len));
	}
	len = 4;
	put[0] = (wc >> 18) + 0xF0;
	put[1] = ((wc >> 12) & 0x3F) + 0x80;
	put[2] = ((wc >> 6) & 0x3F) + 0x80;
	put[3] = (wc & 0x3F) + 0x80;
	return ((int)write(1, put, len));
}

int	ft_display_c(t_form *form)
{
	char	c;
	int		result;

	if (form->hhll == 1)
		return (ft_display_wc(va_arg(form->va_para, wint_t)));
	c = (char)va_arg(form->va_para, int);
	result = 0;
	if (!form->ladjust)
		while (--(form->width) > 0)
			result += (int)write(1, form->padc, 1);
	result += (int)write(1, &c, 1);
	while (--(form->width) > 0)
		result += (int)write(1, " ", 1);
	return (result);
}
