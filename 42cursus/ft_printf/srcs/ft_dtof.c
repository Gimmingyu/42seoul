/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyekim <kyekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:02:31 by kyekim            #+#    #+#             */
/*   Updated: 2021/02/27 12:02:33 by kyekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_mul_2(t_fraction *f)
{
	int	i;

	i = -1;
	while (++i < f->man_len)
		f->man[i] *= 2;
	i = -1;
	while (++i < f->man_len)
		if (f->man[i] > 9)
		{
			f->man[i + 1] += f->man[i] / 10;
			f->man[i] %= 10;
		}
	if (f->man[f->man_len])
		++(f->man_len);
}

void	ft_mul_5(t_fraction *f)
{
	int	i;

	i = -1;
	while (++i < f->man_len)
		f->man[i] *= 5;
	i = -1;
	while (++i < f->man_len)
		if (f->man[i] > 9)
		{
			f->man[i + 1] += f->man[i] / 10;
			f->man[i] %= 10;
		}
	if (f->man[f->man_len])
		++(f->man_len);
}

void	ft_cal_exp(t_fraction *f, int exp)
{
	if (f->exp > 0)
		while ((f->exp)--)
			ft_mul_2(f);
	else
		while ((f->exp)++)
		{
			ft_mul_5(f);
			++exp;
		}
	f->exp = f->man_len - exp;
}

void	ft_cal_man(uint64_t bit, uint64_t len, t_fraction *f)
{
	int	i;

	i = -1;
	while (++i < (int)len)
	{
		ft_mul_5(f);
		if (bit & 1)
			ft_plus_10pow(f, i);
		bit >>= 1;
	}
	if (f->exp)
		ft_cal_exp(f, len);
}

void	ft_dtof(double d, t_fraction *f)
{
	uint64_t	*bits;
	uint64_t	cal;
	int			bits_len;

	bits = (uint64_t *)&d;
	ft_memset((void *)f->man, 0, sizeof(char) * 752);
	f->sign = (*bits >> 63) ? 1 : 0;
	if (!(*bits & 0x7FFFFFFFFFFFFFFF))
	{
		f->exp = 0;
		f->man_len = 0;
		return ;
	}
	bits_len = 53;
	cal = (*bits & 0x000FFFFFFFFFFFFF) + 0x0010000000000000;
	while (!(cal & 1))
	{
		--bits_len;
		cal >>= 1;
	}
	f->exp = (int)((*bits >> 52) & 0x07FF) - 0x03FF;
	f->man_len = 1;
	ft_cal_man(cal, bits_len, f);
}
