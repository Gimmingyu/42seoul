/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:01:14 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:01:24 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_e(t_form *form, t_fraction *f, int frac_len)
{
	int			i;
	char		put[5];

	i = f->man_len - frac_len - 2;
	if (i < -1)
		i = -1;
	while (++i < f->man_len)
		f->man[i] += '0';
	i = ft_subputfracdig(f, 1);
	if (frac_len || form->hash_flag)
		i += (int)write(1, ".", 1);
	i += ft_subputfracdig(f, frac_len);
	ft_initexpput(f->exp, put);
	i += (int)write(1, put, (f->exp > 99 || f->exp < -99) ? 5 : 4);
	return (i);
}

int	ft_display_e(t_form *form, double e)
{
	t_fraction	f_t;
	int			result;
	int			fracdig;

	if ((result = ft_isspecial(e, form)))
		return (result);
	ft_dtof(e, &f_t);
	fracdig = (form->precision < 0) ? 6 : form->precision;
	ft_round_off(&f_t, fracdig);
	if (f_t.sign)
		form->sign = '-';
	form->width -= fracdig + ((fracdig || form->hash_flag) ? 2 : 1) +
		((f_t.exp > 99 || f_t.exp < -99) ? 5 : 4) + (form->sign ? 1 : 0);
	result += ft_put_prepad(form);
	result += ft_put_e(form, &f_t, fracdig);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}
