/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:02:00 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:02:02 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_f(t_form *form, t_fraction *f, int frac_len)
{
	int			i;

	i = f->man_len - f->exp - frac_len - 2;
	if (i < -1)
		i = -1;
	while (++i < f->man_len)
		f->man[i] += '0';
	i = -1;
	if (f->exp >= 0)
		i = ft_subputfracdig(f, f->exp + 1);
	else
		i = (int)write(1, "0", 1);
	if (frac_len || form->hash_flag)
		i += (int)write(1, ".", 1);
	if (f->exp < 0)
		while (++(f->exp))
			if (frac_len-- > 0)
				i += (int)write(1, "0", 1);
	i += ft_subputfracdig(f, frac_len);
	return (i);
}

int	ft_display_f(t_form *form, double f)
{
	t_fraction	f_t;
	int			result;
	int			fracdig;

	if ((result = ft_isspecial(f, form)))
		return (result);
	ft_dtof(f, &f_t);
	if (f_t.sign)
		form->sign = '-';
	fracdig = (form->precision < 0) ? 6 : form->precision;
	ft_round_off(&f_t, fracdig + f_t.exp);
	form->width -= fracdig + ((fracdig || form->hash_flag) ? 2 : 1) +
		(form->sign ? 1 : 0) + (f_t.exp > 0 ? f_t.exp : 0);
	result += ft_put_prepad(form);
	result += ft_put_f(form, &f_t, fracdig);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}
