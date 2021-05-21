/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_g.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:02:10 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:02:11 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_zero(t_fraction *f, int cal, int result, int ef)
{
	if (!(f->man_len))
		return (cal);
	cal = f->man_len - cal - 1;
	if (cal < 0)
	{
		result -= cal;
		cal = 0;
	}
	if (ef && f->exp > 0)
		result += f->exp;
	ef = f->man_len - 1 - ((ef && f->exp > 0) ? f->exp : 0);
	while (cal < ef && f->man[cal] == '0')
	{
		++result;
		++cal;
	}
	if (ef < 0)
		result += ef;
	return (result);
}

int	ft_put_ge(int fracdig, t_form *form, t_fraction *f)
{
	int		result;
	char	put[5];

	form->width -= fracdig + (fracdig || form->hash_flag ? 2 : 1) +
		(form->sign ? 1 : 0) + ((f->exp > 99 || f->exp < -99) ? 5 : 4);
	result = ft_put_prepad(form);
	result += ft_subputfracdig(f, 1);
	if (fracdig || form->hash_flag)
		result += (int)write(1, ".", 1);
	result += ft_subputfracdig(f, fracdig);
	ft_initexpput(f->exp, put);
	result += (int)write(1, put, (f->exp > 99 || f->exp < -99) ? 5 : 4);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}

int	ft_put_gf(int fracdig, int intdig, t_form *form, t_fraction *f)
{
	int result;

	if (intdig > 0)
		form->width -= (fracdig || form->hash_flag ? 1 : 0) +
			intdig + fracdig + (form->sign ? 1 : 0);
	else
		form->width -= fracdig - intdig + (form->sign ? 4 : 3);
	result = ft_put_prepad(form);
	if (intdig > 0)
	{
		result += ft_subputfracdig(f, intdig);
		if (fracdig || form->hash_flag)
			result += (int)write(1, ".", 1);
		result += ft_subputfracdig(f, fracdig);
	}
	else
		result += ft_subput_gf(f, --intdig, ++fracdig);
	while (form->width-- > 0)
		result += (int)write(1, " ", 1);
	return (result);
}

int	ft_display_g(t_form *form, double g)
{
	t_fraction	f_t;
	int			result;
	int			dig_max;

	if ((result = ft_isspecial(g, form)))
		return (result);
	ft_dtof(g, &f_t);
	dig_max = (form->precision < 0) ? 6 : form->precision;
	if (dig_max)
		--dig_max;
	ft_round_off(&f_t, dig_max);
	ft_fctoc(&f_t, dig_max + 1);
	if (f_t.sign)
		form->sign = '-';
	if (f_t.exp > dig_max || f_t.exp < -4)
	{
		if (!(form->hash_flag))
			dig_max -= ft_check_zero(&f_t, dig_max, 0, 0);
		return (ft_put_ge(dig_max, form, &f_t));
	}
	if (!(form->hash_flag))
		dig_max -= ft_check_zero(&f_t, dig_max, 0, 1);
	return (ft_put_gf(dig_max, f_t.exp + 1, form, &f_t));
}
